#include <iostream>
#include <random>
#include "../include/BaseballGame.h"
#include <time.h>

using namespace std;

BaseballGame::BaseballGame() {
    answerNumberString = "";
    userNumberString = "";
    numOfStrike = 0;
    numOfBall = 0;
    m_isGameDone = false;
}

bool BaseballGame::isGameDone() {
    return m_isGameDone;
}

void BaseballGame::initialize() {
    answerNumberString = "";
    userNumberString = "";
    numOfStrike = 0;
    numOfBall = 0;
    srand(time(NULL));
    generate3DigitRandomNumber();
}

int BaseballGame::getNumOfStrike() {
    return numOfStrike;
}

bool BaseballGame::isNumber(char ch) {
    bool res = false;
    if (ch >= '0' && ch <= '9') {
        res = true;
    };
    return res;
}

bool BaseballGame::isInputNumberWrong() {
    bool res = false;
    if (userNumberString.size() != 3) {
        res = true;
    } else {
        for (int i = 0; i < userNumberString.size(); i++) {
            if (!isNumber(userNumberString[i])) {
                res = true;
                break;
            }
        }
    }
    return res;
}

void BaseballGame::input() {
    userNumberString = "";
    while (isInputNumberWrong()) {
        cout << "3자리 숫자를 입력해주세요. 중복되는 숫자는 입력할 수 없습니다." << endl;
        cin >> userNumberString;
    }
}

void BaseballGame::judge() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (userNumberString[i] == answerNumberString[j]) {
                if (i == j) {
                    numOfStrike++;
                } else {
                    numOfBall++;
                }
            }
        }
    }    
}

void BaseballGame::output() {
    cout << "Strike(";
    cout << numOfStrike;
    cout << "), ";
    cout << "Ball(";
    cout << numOfBall;
    cout << ")" << endl;

    if (numOfStrike == 3) {
        char yOrN;
        cout << "숫자를 맞추셨습니다." << endl;
        cout << "다시 하시겠습니까?(Y/N)";
        cin >> yOrN;

        if (yOrN == 'Y' || yOrN == 'y') {
            m_isGameDone = false;
        } else if (yOrN == 'N' || yOrN == 'n') {
            m_isGameDone = true;
        }

    } else {
        cout << "틀렸습니다." << endl;
        numOfStrike = 0;
        numOfBall = 0;
    }
}

void BaseballGame::generate3DigitRandomNumber() {

    bool hasNumber[10] = {
        false,
    };
    int number;
    number = rand() % 10;

    while (answerNumberString.size() != 3) {
        while (hasNumber[number]) {
            number = rand() % 10;
        }
        answerNumberString += to_string(number);
        hasNumber[number] = true;
    }

    cout << answerNumberString << endl;
}
