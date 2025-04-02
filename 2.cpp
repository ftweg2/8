#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

// 结构体模板
struct FootballTeam {
    string name;    // 队伍名称
    string city;    // 所在城市
    int points;     // 积分

    // 用于排序的比较运算符重载
    bool operator<(const FootballTeam& other) const {
        return points > other.points; // 降序排列
    }
};

// 输入验证函数
int getValidInput(const string& prompt, int minVal, int maxVal) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < minVal || value > maxVal) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "输入无效，请重新输入 (范围: " << minVal << "-" << maxVal << ")\n";
        } else {
            break;
        }
    }
    return value;
}

// 打印队伍表格
void printTeams(const vector<FootballTeam>& teams) {
    cout << "\n当前队伍排名:\n";
    cout << "+----------------------+----------------------+----------+\n";
    cout << "| " << left << setw(20) << "队伍名称" 
         << "| " << setw(20) << "城市" 
         << "| " << setw(8) << "积分" << "|\n";
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

    // 主菜单
    while (true) {
        cout << "\n足球联赛管理系统\n";
        cout << "1. 输入初始10支队伍数据\n";
        cout << "2. 显示所有队伍\n";
        cout << "3. 添加新队伍并分析排名\n";
        cout << "4. 显示积分低于最后一支队伍的队伍\n";
        cout << "5. 退出\n";
        cout << "请选择操作: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                // 输入10支队伍数据
                teams.clear();
                for (int i = 0; i < initialSize; ++i) {
                    FootballTeam team;
                    cout << "\n输入第 " << i+1 << " 支队伍信息:\n";
                    
                    cout << "队伍名称: ";
                    cin.ignore();
                    getline(cin, team.name);
                    
                    cout << "所在城市: ";
                    getline(cin, team.city);
                    
                    team.points = getValidInput("获得积分 (0-100): ", 0, 100);
                    
                    teams.push_back(team);
                }
                sort(teams.begin(), teams.end());
                cout << "初始数据输入完成并已排序!\n";
                break;
            }
            
            case 2:
                if (teams.empty()) {
                    cout << "当前没有队伍数据，请先输入数据!\n";
                } else {
                    printTeams(teams);
                }
                break;
                
            case 3: {
                if (teams.size() < initialSize) {
                    cout << "请先输入初始10支队伍数据!\n";
                    break;
                }
                
                // 添加新队伍
                FootballTeam newTeam;
                cout << "\n输入新队伍信息:\n";
                cout << "队伍名称: ";
                cin.ignore();
                getline(cin, newTeam.name);
                
                cout << "所在城市: ";
                getline(cin, newTeam.city);
                
                newTeam.points = getValidInput("获得积分 (0-100): ", 0, 100);
                
                // 插入并重新排序
                teams.push_back(newTeam);
                sort(teams.begin(), teams.end());
                
                // 查找新队伍的排名
                auto it = find_if(teams.begin(), teams.end(), 
                    [&newTeam](const FootballTeam& t) { return t.name == newTeam.name; });
                
                if (it != teams.end()) {
                    int position = distance(teams.begin(), it) + 1;
                    cout << "\n新队伍 '" << newTeam.name << "' 当前排名: " << position << "\n";
                }
                
                printTeams(teams);
                break;
            }
            
            case 4: {
                if (teams.empty()) {
                    cout << "没有队伍数据!\n";
                    break;
                }
                
                // 显示积分低于最后一名的队伍
                const FootballTeam& lastTeam = teams.back();
                cout << "\n积分低于最后一支队伍 '" << lastTeam.name 
                     << "' (" << lastTeam.points << "分) 的队伍:\n";
                
                bool found = false;
                for (const auto& team : teams) {
                    if (team.points < lastTeam.points) {
                        cout << "- " << team.name << " (" << team.points << "分)\n";
                        found = true;
                    }
                }
                
                if (!found) {
                    cout << "没有队伍积分低于最后一支队伍\n";
                }
                break;
            }
            
            case 5:
                cout << "程序退出。\n";
                return 0;
                
            default:
                cout << "无效选择，请重新输入!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    return 0;
}
