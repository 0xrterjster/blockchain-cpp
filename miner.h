#ifndef MINER_H
#define MINER_H

#include <string>
#include <mutex>
#include "block.h"
#include "user.h"

class Miner {
public:
    std::mutex *mtx;
    User *user;
    std::string zeros;
    int difficulty;
    Block currentBlock;
    void sendingBlock();
    void start(User *user1, std::mutex *setMtx, int setDifficulty);
    void addingData(std::string newData);
    void mining();
};

#endif