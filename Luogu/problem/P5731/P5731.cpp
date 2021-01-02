// R36471603

#include<bits/stdc++.h>

using namespace std;

int n, k, a[15][15], ax, ay;


int main() {
    k = ax = 1;

    scanf("%d", &n);
    
    /**
     * ax, ay+1 -> 右侧
     * ax, ay-1 -> 左侧
     * ax+1, ay -> 下方
     * ax-1, ay -> 上方
     * 
     * 0 --- 1 ---------- ay ----------> n
     * | +------+------+------+------+------+
     * 1 |      |      | ax-1 |      |      |
     * | |      |      |  ay  |      |      |
     * | +------+------+------+------+------+
     * a |      |  ax  |  ax  |  ax  |      |
     * x |      | ay-1 |  ay  | ay+1 |      |
     * | +------+------+------+------+------+
     * | |      |      | ax+1 |      |      |
     * | |      |      |  ay  |      |      |
     * | +------+------+------+------+------+
     * | |      |      |      |      |      |
     * | |      |      |      |      |      |
     * | +------+------+------+------+------+
     * | |      |      |      |      |      |
     * n |      |      |      |      |      | n
     *   +------+------+------+------+------+
     *                                   n
     */

    while(k <= n*n) {
        while(ay < n && !a[ax][ay+1]) { // 右侧  不过边界 && 未填数
            a[ax][++ay] = k++;
        }
        while(ax < n && !a[ax+1][ay]) { // 下方  不过边界 && 未填数
            a[++ax][ay] = k++;
        }
        while(ay > 1 && !a[ax][ay-1]) { // 左侧  不过边界 && 未填数
            a[ax][--ay] = k++;
        }
        while(ax > 1 && !a[ax-1][ay]) { // 上方  不过边界 && 未填数
            a[--ax][ay] = k++;
        }
    }

    for(int i = 1 ; i <= n ; i++) {
        for(int j = 1 ; j <= n ; j++) {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}