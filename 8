#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

struct FootballTeam {
    string name;    // Название команды
    string city;    // Город
    int points;     // Количество очков

  
    bool operator<(const FootballTeam& other) const {
        return points > other.points;
    }
};

int getValidInput(const string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Неверный ввод. Пожалуйста, введите значение от " << minVal << " до " << maxVal << ".\n";
        } else {
            break;
        }
    }
    return value;
}

void printTeams(const vector<FootballTeam>& teams) {
    cout << "\nТекущий рейтинг команд:\n";
    cout << "+----------------------+----------------------+----------+\n";
    cout << "| " << left << setw(20) << "Название команды" 
         << "| " << setw(20) << "Город" 
         << "| " << setw(8) << "Очки" << "|\n";
    cout << "+----------------------+----------------------+----------+\n";

    for (size_t i = 0; i < teams.size(); ++i) {
        cout << "| " << setw(20) << teams[i].name 
             << "| " << setw(20) << teams[i].city 
             << "| " << setw(8) << teams[i].points << "|\n";
    }
    cout << "+----------------------+----------------------+----------+\n";
}

int main() {
    vector<FootballTeam> teams;
    const int initialSize = 10;


    while (true) {
        cout << "\nСистема управления футбольным чемпионатом\n";
        cout << "1. Ввести данные 10 команд\n";
        cout << "2. Показать все команды\n";
        cout << "3. Добавить новую команду и определить ее позицию\n";
        cout << "4. Показать команды с меньшим количеством очков, чем последняя\n";
        cout << "5. Выход\n";
        cout << "Выберите действие: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // Ввод данных 10 команд
                teams.clear();
                for (int i = 0; i < initialSize; ++i) {
                    FootballTeam team;
                    cout << "\nВведите данные команды № " << i+1 << ":\n";
                    
                    cout << "Название команды: ";
                    cin.ignore();
                    getline(cin, team.name);
                    
                    cout << "Город: ";
                    getline(cin, team.city);
                    
                    team.points = getValidInput("Количество очков (0-100): ", 0, 100);
                    
                    teams.push_back(team);
                }
                sort(teams.begin(), teams.end());
                cout << "Данные успешно введены и отсортированы!\n";
                break;
            }
            
            case 2:
                if (teams.empty()) {
                    cout << "Нет данных о командах. Сначала введите данные!\n";
                } else {
                    printTeams(teams);
                }
                break;
                
            case 3: {
                if (teams.size() < initialSize) {
                    cout << "Сначала введите данные 10 команд!\n";
                    break;
                }
                
                // Добавление новой команды
                FootballTeam newTeam;
                cout << "\nВведите данные новой команды:\n";
                cout << "Название команды: ";
                cin.ignore();
                getline(cin, newTeam.name);
                
                cout << "Город: ";
                getline(cin, newTeam.city);
                
                newTeam.points = getValidInput("Количество очков (0-100): ", 0, 100);
                
                // Вставка и сортировка
                teams.push_back(newTeam);
                sort(teams.begin(), teams.end());
                
                // Определение позиции новой команды
                auto it = find_if(teams.begin(), teams.end(), 
                    [&newTeam](const FootballTeam& t) { return t.name == newTeam.name; });
                
                if (it != teams.end()) {
                    int position = distance(teams.begin(), it) + 1;
                    cout << "\nНовая команда '" << newTeam.name << "' занимает позицию: " << position << "\n";
                }
                
                printTeams(teams);
                break;
            }
            
            case 4: {
                if (teams.empty()) {
                    cout << "Нет данных о командах!\n";
                    break;
                }
                
                // Вывод команд с меньшим количеством очков, чем последняя
                const FootballTeam& lastTeam = teams.back();
                cout << "\nКоманды с меньшим количеством очков, чем '" << lastTeam.name 
                     << "' (" << lastTeam.points << " очков):\n";
                
                bool found = false;
                for (const auto& team : teams) {
                    if (team.points < lastTeam.points) {
                        cout << "- " << team.name << " (" << team.points << " очков)\n";
                        found = true;
                    }
                }
                
                if (!found) {
                    cout << "Нет команд с меньшим количеством очков, чем последняя\n";
                }
                break;
            }
            
            case 5:
                cout << "Программа завершена.\n";
                return 0;
                
            default:
                cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
