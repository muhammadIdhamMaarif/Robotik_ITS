#include <iostream>
#include <vector>
using namespace std;

/*
    ==========================================
                  Made by Idham
              Universitas Brawijaya
    ==========================================

*/

class Robot {
public:
    int x, y;
    bool canPassWalls;
    int speed;
    int time;

    Robot(int startX, int startY) {
        x = startX;
        y = startY;
        canPassWalls = false;
        speed = 2;
        time = 0;
    }

    void move(char direction, const vector<vector<char>>& map) {
        int newX = x, newY = y;

        if (direction == 'U') newX--;
        else if (direction == 'D') newX++;
        else if (direction == 'L') newY--;
        else if (direction == 'R') newY++;

        if (newX < 0 || newY < 0 || newX >= map.size() || newY >= map[0].size()) {
            cout << "Robot nabrak, silahkan diperbaiki\n";
            return;
        }

        char tile = map[newX][newY];
        if (tile == 'x' && !canPassWalls) {
            cout << "Robot nabrak, silahkan diperbaiki\n";
            return;
        }
        else {
            x = newX;
            y = newY;
            time += speed;
        }

        if (tile == 'M') {
            cout << "Bertemu dengan mekanik, siap membasmi rintangan\n";
            canPassWalls = true;
        }
        else if (tile == 'E') {
            cout << "Bertemu dengan electrical, kecepatan roda naik menjadi 200%\n";
            speed = 1;  
        }
        else if (tile == 'P') {
            cout << "Hi Programmer\n";
        }
        else if (tile == 'O') {
            cout << "Bertemu dengan official, diajak ngonten bareng\n";
            time *= 2;
        }
    }
};

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<char>> map(M, vector<char>(N));
    int startX, startY, endX, endY;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'S') {
                startX = i;
                startY = j;
            }
            if (map[i][j] == 'F') {
                endX = i;
                endY = j;
            }
        }
    }

    int P;
    cin >> P;
    vector<char> moves(P);

    for (int i = 0; i < P; i++) {
        cin >> moves[i];
    }

    Robot robot(startX, startY);
    bool reachedGoal = false;

    for (int i = 0; i < P; i++) {
        robot.move(moves[i], map);
        if (robot.x == endX && robot.y == endY) {
            reachedGoal = true;
            break;
        }
    }

    if (reachedGoal) {
        cout << "Robot berhasil mencapai tujuan\n";
    }
    else {
        cout << "Robot gagal dalam mencapai tujuan :(\n";
    }

    cout << "Robot telah berjalan selama " << robot.time << " menit\n";

    return 0;
}
