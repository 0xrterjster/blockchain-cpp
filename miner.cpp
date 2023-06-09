#include <iostream>
#include "miner.h"
#include "block.h"
#include "user.h"
#include <thread>

using namespace std;

void Miner::start(User* setUser, mutex* setMtx, int setDifficulty) {
    mtx = setMtx;
    user = setUser;
    currentBlock.createBlock(0, "0");
    currentBlock.hash = currentBlock.hashFunction();
    currentBlock.createBlock(1, currentBlock.hash);
    difficulty = setDifficulty;
    zeros = "000000000000000000000000000000";
    zeros = zeros.substr(0, difficulty);
    thread miner(&Miner::mining, this);
    miner.detach();
}

void Miner::sendingBlock() {
    (*user).setBlock(currentBlock);
    currentBlock.createBlock(currentBlock.number + 1, currentBlock.hash);
}

void Miner::addingData(string newData) {
    (*mtx).lock();
    currentBlock.addingData(newData);
    (*mtx).unlock();
}

void Miner::mining() {
    while (1) {
        while (currentBlock.hashFunction().substr(0, difficulty) != zeros) {
            currentBlock.nonce++;
        }
        (*mtx).lock();
        currentBlock.hash = currentBlock.hashFunction();
        sendingBlock();
        (*mtx).unlock();
    }
}