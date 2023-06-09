#include <iostream>
#include "sha256.h"
#include "block.h"
using namespace std;

void Block::createBlock(int setNumber, string setPrevHash){
    prevHash=setPrevHash;
    number=setNumber;
    nonce=0;
    hash="";
    data="";
}

void Block::addingData(string newData){
    data+=newData;
}

string Block::hashFunction(){
    return sha256(to_string(number) + data + prevHash + to_string(nonce));
}