#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>  // C++17 이상 필요

using namespace std;
namespace fs = filesystem;

struct Week {
    string folderName;
    string topic;
};

string makeSummaryTemplate(const string& title) {
    return
"# 📚 요약 정리 - " + title + "\n\n"
"## ✅ 주요 개념\n\n"
"- 여기에 개념 요약을 작성하세요.\n\n"
"## 🧠 배운 점\n\n"
"- 직접 느낀 것, 실수한 것, 개선할 점을 적어보세요.\n\n"
"## 📝 문제 목록\n\n"
"| 번호 | 문제명 | 유형 | 링크 | 난이도 |\n"
"|------|--------|------|------|--------|\n"
"| 1 |          |      |      |        |\n\n"
"## 💡 느낀 점\n\n"
"- 오늘의 공부를 짧게 정리해보세요!\n";
}

int main() {
    vector<Week> weeks = {
        {"week01_BFS_DFS", "DFS / BFS"},
        {"week02_Implementation", "구현 / 시뮬레이션"},
        {"week03_Sorting_Greedy", "정렬 / 그리디"},
        {"week04_Backtracking", "백트래킹 / 완전탐색"},
        {"week05_DP_Basics", "DP 기초"},
        {"week06_DP_Advanced", "DP 심화"},
        {"week07_Stack_Queue", "자료구조 1"},
        {"week08_Heap_Tree", "자료구조 2"},
        {"week09_BinarySearch", "이분 탐색"},
        {"week10_Tree_Basics", "트리 기초"},
        {"week11_Graph_Basics", "그래프 기초"},
        {"week12_ShortestPath", "최단 경로"},
        {"week13_MST_UnionFind", "MST / 유니온 파인드"},
        {"week14_KOI_Practice", "기출 문제 풀이"}
    };

    for (const auto& week : weeks) {
        fs::create_directory(week.folderName);
        string summaryPath = week.folderName + "/summary.md";
        ofstream out(summaryPath);
        if (out.is_open()) {
            out << makeSummaryTemplate(week.topic);
            out.close();
            cout << "✅ Created: " << week.folderName << "/summary.md" << endl;
        } else {
            cerr << "❌ Failed to create: " << summaryPath << endl;
        }
    }

    cout << "\n🎉 모든 폴더와 summary.md 생성 완료!" << endl;
    return 0;
}
