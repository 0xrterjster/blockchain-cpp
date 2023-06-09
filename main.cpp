#include <iostream>
#include "sha256.h"
#include "block.h"
#include "user.h"
#include "miner.h"
#include <thread>
#include <mutex>
using namespace std;
mutex mtx;

int main()
{
    int difficulty = 5;
    Miner miner;
    User user;
    miner.start(&user, &mtx, difficulty);
    user.start(difficulty);
    string input;
    while(true){
        cin >> input;
        if (input=="showData"){
            user.showData();
        }
        else if (input=="showChain"){
            user.showChain();
        }
        else if (input=="check"){
            if (user.check())
                cout << "Blockchain is valid" << endl;
            else
                cout << "Blockchain is corrupted" << endl;
        }
        else{
            miner.addingData(input);
        }
    }
    return 0;
}