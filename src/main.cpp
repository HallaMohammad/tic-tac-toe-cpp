#include <iostream>
#include <array>
class Board {
  std::array<char, 9> cells;
public:
Board() { cells.fill(' '); }
void print() const {
  std::cout <<"\n";
for (int i = 0; i < 9; i += 3) {
std::cout << " " << cells[i] << " | " << cells[i+1] << " | " << cells[i+2] << "\n";
if (i < 6) std::cout << "---+---+---\n";
}
std::cout << "\n";
}
bool place(int pos, char player) {
  if (pos < 1 || pos > 9 || cells[pos-1] != ' ') return false;
cells[pos-1] = player;
return true;
}
bool hasWon(char p) const {
  const int lines[8][3] = {
{0,1,2} , {3,4,5} , {6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}
};
for (auto& line : lines)
  if(cells[line[0]] == p && cells[line[1]] == p && cells[line[2]] == p)
    return true;
return false;
}
bool isFull() const {
  for (char c : cells) if (c == ' ') return false;
return true;
}
};
int main() {
char again ='y';
  while (again == 'y' || again == 'Y') {
    Board board;
    char player = 'X';
while (true) {
board.print();
std::cout << "Player " << player << " (1-9): ";
int pos;
if (!(std::cin >> pos)) return 0;
if (!board.place(pos, player)) {
std::cout << "Invalid move, try again.\n";
continue;
}
if (board.hasWon(player)) {
board.print();
std::cout << "Player " << player << " wins!\n";
break;
}
if (board.isFull()) {
board.print();
std::cout << "Draw!\n";
break;
}
player = (player == 'X') ? 'O' :'X'; 
}
    std::cout << " Play again? (y/n):";
    std::cin >> again;
  }
}
}
