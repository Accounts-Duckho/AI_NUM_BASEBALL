#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "game.h"
#include "deco.h"
// WIN = 0, LOSE = 1
// FIRST = 0 , MIDDLE = 1, LAST = 2
// YES = 1, VERYHIGH = 2, HIGH = 3, NORMAL = 4, LOW = 5, SOLOW = 6 ,VERYLOW = 7, NO = 8
struct num {
  int first;
  int middle;
  int last;
};
struct record {
  int first;
  int middle;
  int last;
};
int main(void) {
  system("mode con:cols=50 lines=15");
  drawLine(50, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(14);
  printf("A.I와 숫자야구 대결");
  addBlank(15);
  drawLine(1, '*');
  printf("\n");
  drawLine(50, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(2);
  printf("[게임방법]");
  addBlank(36);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(4);
  printf("수가 중복되지 않는 3자리수를 생각합니다.");
  addBlank(4);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(4);
  printf("각 라운드마다 컴퓨터가 수를 출력합니다.");
  addBlank(5);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(4);
  printf("생각한 수와 비교합니다.");
  addBlank(21);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(2);
  printf("자리수까지 일치하면 S, 수만 일치하면 B입니다.");
  addBlank(1);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(2);
  printf("[예시] 369->398 : 1S 1B");
  addBlank(23);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(4);
  printf("10라운드까지 컴퓨터는 수를 맞춰나갑니다.");
  addBlank(4);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(4);
  printf("그 안에 맞추면 컴퓨터의 승리이며");
  addBlank(12);
  drawLine(1, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(4);
  printf("그 안에 맞추지 못하면 유저의 승리입니다.");
  addBlank(4);
  drawLine(1, '*');
  printf("\n");
  drawLine(50, '*');
  printf("\n");
  loadGame();
  return 0;
}
void loadGame(void) {
  int choice_start;
  addBlank(2);
  printf("게임 시작은 1번, 종료는 2번을 입력\n");
  scanf("%d", &choice_start);
  if(choice_start==1) {
    system("cls");
    startGame(NULL);
  }
  else if(choice_start==2) {
    return;
  }
  else {
    drawLine(50, '*');
    printf("\n");
    loadGame();
    return;
  }
  return;
}
void startGame(int* guess_answer) {
  system("cls");
  static struct num num[10];
  static int round_strike[15]={0};
  static int round_ball[15]={0};
  static struct record record[50];
  static int count=1;
  int result_sum;
  drawLine(50, '*');
  printf("\n");
  drawLine(1, '*');
  addBlank(2);
  printf("[%dR]", count);
  if(count==1) {
    addBlank(4);
    printf("PC : 147");
    addBlank(30);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    record[count].first=1;
    record[count].middle=4;
    record[count].last=7;
    drawLine(1, '*');
    addBlank(2);
    printf("스트라이크와 볼의 수를 입력해주세요.");
    addBlank(10);
    drawLine(1, '*');
    printf("\n");
    drawLine(1, '*');
    addBlank(2);
    printf("(예시) 1s 1b -> 1 1");
    addBlank(27);
    drawLine(1, '*');
    printf("\n");
    drawLine(1, '*');
    addBlank(2);
    printf("OUT은 0s 0b로 간주합니다.");
    addBlank(21);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    scanf("%d %d", &round_strike[count], &round_ball[count]);
    result_sum=round_strike[count]+round_ball[count];
    if(result_sum<=3 && result_sum>=0) {
      if(3>=round_strike[count] && 3>=round_ball[count]) {
        if(round_strike[count]>=0 && round_ball[count]>=0) {
          if(round_strike[count]==3) resultGame(LOSE);
          else if(round_strike[count]==2) {
            if(round_ball[count]==1) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              num[1].first=VERYHIGH;
              num[1].middle=LOW;
              num[1].last=LOW;

              num[4].first=LOW;
              num[4].middle=VERYHIGH;
              num[4].last=LOW;

              num[7].first=LOW;
              num[7].middle=LOW;
              num[7].last=VERYHIGH;

              count++;
              startGame(NULL);
            }
            else if(round_ball[count]==0) {
              num[1].first=HIGH;
              num[1].middle=NO;
              num[1].last=NO;

              num[4].first=NO;
              num[4].middle=HIGH;
              num[4].last=NO;

              num[7].first=NO;
              num[7].middle=NO;
              num[7].last=HIGH;
              count++;
              startGame(NULL);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[1].first=num[1].middle=num[1].last=0;
              num[4].first=num[4].middle=num[4].last=0;
              num[7].first=num[7].middle=num[7].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
          else if(round_strike[count]==1) {
            if(round_ball[count]==2) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              num[1].first=NORMAL;
              num[1].middle=HIGH;
              num[1].last=HIGH;

              num[4].first=HIGH;
              num[4].middle=NORMAL;
              num[4].last=HIGH;

              num[7].first=HIGH;
              num[7].middle=HIGH;
              num[7].last=NORMAL;
              count++;
              startGame(NULL);
            }
            else if(round_ball[count]==1) {
              num[1].first=LOW;
              num[1].middle=SOLOW;
              num[1].last=SOLOW;

              num[4].first=SOLOW;
              num[4].middle=LOW;
              num[4].last=SOLOW;

              num[7].first=SOLOW;
              num[7].middle=SOLOW;
              num[7].last=LOW;
              count++;
              startGame(NULL);
            }
            else if(round_ball[count]==0) {
              num[1].first=VERYLOW;
              num[1].middle=NO;
              num[1].last=NO;

              num[4].first=NO;
              num[4].middle=VERYLOW;
              num[4].last=NO;

              num[7].first=NO;
              num[7].middle=NO;
              num[7].last=VERYLOW;
              count++;
              startGame(NULL);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[1].first=num[1].middle=num[1].last=0;
              num[4].first=num[4].middle=num[4].last=0;
              num[7].first=num[7].middle=num[7].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
          else if(round_strike[count]==0) {
            if(round_ball[count]==3) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              num[1].first=NO;
              num[1].middle=VERYHIGH;
              num[1].last=VERYHIGH;

              num[4].first=VERYHIGH;
              num[4].middle=NO;
              num[4].last=VERYHIGH;

              num[7].first=VERYHIGH;
              num[7].middle=VERYHIGH;
              num[7].last=NO;
              count++;
              startGame(NULL);
            }
            else if(round_ball[count]==2) {
              num[1].first=NO;
              num[1].middle=NORMAL;
              num[1].last=NORMAL;

              num[4].first=NORMAL;
              num[4].middle=NO;
              num[4].last=NORMAL;

              num[7].first=NORMAL;
              num[7].middle=NORMAL;
              num[7].last=NO;
              count++;
              startGame(NULL);
            }
            else if(round_ball[count]==1) {
              num[1].first=NO;
              num[1].middle=VERYLOW;
              num[1].last=VERYLOW;

              num[4].first=VERYLOW;
              num[4].middle=NO;
              num[4].last=VERYLOW;

              num[7].first=VERYLOW;
              num[7].middle=VERYLOW;
              num[7].last=NO;
              count++;
              startGame(NULL);
            }
            else if(round_ball[count]==0) {
              num[1].first=NO;
              num[1].middle=NO;
              num[1].last=NO;

              num[4].first=NO;
              num[4].middle=NO;
              num[4].last=NO;

              num[7].first=NO;
              num[7].middle=NO;
              num[7].last=NO;
              count++;
              startGame(NULL);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[1].first=num[1].middle=num[1].last=0;
              num[4].first=num[4].middle=num[4].last=0;
              num[7].first=num[7].middle=num[7].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
        }
        else {
          drawLine(50, '*');
          printf("\n");
          drawLine(1, '*');
          addBlank(2);
          printf("ERROR : STRIKE OR BALL CANNOT BE MINUS");
          addBlank(8);
          drawLine(1, '*');
          printf("\n");
          drawLine(1, '*');
          addBlank(2);
          printf("한 라운드 전으로 게임을 되돌립니다.");
          addBlank(11);
          drawLine(1, '*');
          printf("\n");
          round_strike[count]=round_ball[count]=0;
          startGame(NULL);
          return;
        }
      }
      else {
        drawLine(50, '*');
        printf("\n");
        drawLine(1, '*');
        addBlank(2);
        printf("ERROR : STRIKE OR BALL CANNOT BE MORE THAN 3");
        addBlank(2);
        drawLine(1, '*');
        printf("\n");
        drawLine(1, '*');
        addBlank(2);
        printf("한 라운드 전으로 게임을 되돌립니다.");
        addBlank(11);
        drawLine(1, '*');
        printf("\n");
        round_strike[count]=round_ball[count]=0;
        startGame(NULL);
        return;
      }
    }
    else {
      drawLine(50, '*');
      printf("\n");
      drawLine(1, '*');
      addBlank(2);
      printf("ERR : S+B CANNOT BE MORE THAN 6, LESS THAN 0");
      addBlank(2);
      drawLine(1, '*');
      printf("\n");
      drawLine(1, '*');
      addBlank(2);
      printf("한 라운드 전으로 게임을 되돌립니다.");
      addBlank(11);
      drawLine(1, '*');
      printf("\n");
      round_strike[count]=round_ball[count]=0;
      startGame(NULL);
      return;
    }
  }
  else if(count==2) {
    addBlank(4);
    printf("PC : 258");
    addBlank(30);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    record[count].first=2;
    record[count].middle=5;
    record[count].last=8;
    drawLine(1, '*');
    addBlank(2);
    printf("스트라이크와 볼의 수를 입력해주세요.");
    addBlank(10);
    drawLine(1, '*');
    printf("\n");
    drawLine(1, '*');
    addBlank(2);
    printf("(예시) 1s 1b -> 1 1");
    addBlank(27);
    drawLine(1, '*');
    printf("\n");
    drawLine(1, '*');
    addBlank(2);
    printf("OUT은 0s 0b로 간주합니다.");
    addBlank(21);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    scanf("%d %d", &round_strike[count], &round_ball[count]);
    result_sum=round_strike[count]+round_ball[count];
    if(result_sum<=3 && result_sum>=0) {
      if(3>=round_strike[count] && 3>=round_ball[count]) {
        if(round_strike[count]>=0 && round_ball[count]>=0) {
          if(round_strike[count]==3) resultGame(LOSE);
          else if(round_strike[count]==2) {
            if(round_ball[count]==1) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[2].first, VERYHIGH);
              evaluate(&num[2].middle, LOW);
              evaluate(&num[2].last, LOW);

              evaluate(&num[5].first, LOW);
              evaluate(&num[5].middle, VERYHIGH);
              evaluate(&num[5].last, LOW);

              evaluate(&num[8].first, LOW);
              evaluate(&num[8].middle, LOW);
              evaluate(&num[8].last, VERYHIGH);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              evaluate(&num[2].first, HIGH);
              evaluate(&num[2].middle, NO);
              evaluate(&num[2].last, NO);

              evaluate(&num[5].first, NO);
              evaluate(&num[5].middle, HIGH);
              evaluate(&num[5].last, NO);

              evaluate(&num[8].first, NO);
              evaluate(&num[8].middle, NO);
              evaluate(&num[8].last, HIGH);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[2].first=num[2].middle=num[2].last=0;
              num[5].first=num[5].middle=num[5].last=0;
              num[8].first=num[8].middle=num[8].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
          else if(round_strike[count]==1) {
            if(round_ball[count]==2) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[2].first, NORMAL);
              evaluate(&num[2].middle, HIGH);
              evaluate(&num[2].last, HIGH);

              evaluate(&num[5].first, HIGH);
              evaluate(&num[5].middle, NORMAL);
              evaluate(&num[5].last, HIGH);

              evaluate(&num[8].first, HIGH);
              evaluate(&num[8].middle, HIGH);
              evaluate(&num[8].last, NORMAL);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==1) {
              evaluate(&num[2].first, LOW);
              evaluate(&num[2].middle, SOLOW);
              evaluate(&num[2].last, SOLOW);

              evaluate(&num[5].first, SOLOW);
              evaluate(&num[5].middle, LOW);
              evaluate(&num[5].last, SOLOW);

              evaluate(&num[8].first, SOLOW);
              evaluate(&num[8].middle, SOLOW);
              evaluate(&num[8].last, LOW);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              evaluate(&num[2].first, VERYLOW);
              evaluate(&num[2].middle, NO);
              evaluate(&num[2].last, NO);

              evaluate(&num[5].first, NO);
              evaluate(&num[5].middle, VERYLOW);
              evaluate(&num[5].last, NO);

              evaluate(&num[8].first, NO);
              evaluate(&num[8].middle, NO);
              evaluate(&num[8].last, VERYLOW);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[2].first=num[2].middle=num[2].last=0;
              num[5].first=num[5].middle=num[5].last=0;
              num[8].first=num[8].middle=num[8].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
          else if(round_strike[count]==0) {
            if(round_ball[count]==3) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[2].first, NO);
              evaluate(&num[2].middle, VERYHIGH);
              evaluate(&num[2].last, VERYHIGH);

              evaluate(&num[5].first, VERYHIGH);
              evaluate(&num[5].middle, NO);
              evaluate(&num[5].last, VERYHIGH);

              evaluate(&num[8].first, VERYHIGH);
              evaluate(&num[8].middle, VERYHIGH);
              evaluate(&num[8].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==2) {
              evaluate(&num[2].first, NO);
              evaluate(&num[2].middle, NORMAL);
              evaluate(&num[2].last, NORMAL);

              evaluate(&num[5].first, NORMAL);
              evaluate(&num[5].middle, NO);
              evaluate(&num[5].last, NORMAL);

              evaluate(&num[8].first, NORMAL);
              evaluate(&num[8].middle, NORMAL);
              evaluate(&num[8].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==1) {
              evaluate(&num[2].first, NO);
              evaluate(&num[2].middle, VERYLOW);
              evaluate(&num[2].last, VERYLOW);

              evaluate(&num[5].first, VERYLOW);
              evaluate(&num[5].middle, NO);
              evaluate(&num[5].last, VERYLOW);

              evaluate(&num[8].first, VERYLOW);
              evaluate(&num[8].middle, VERYLOW);
              evaluate(&num[8].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              num[2].first=NO;
              num[2].middle=NO;
              num[2].last=NO;

              num[5].first=NO;
              num[5].middle=NO;
              num[5].last=NO;

              num[8].first=NO;
              num[8].middle=NO;
              num[8].last=NO;
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[2].first=num[2].middle=num[2].last=0;
              num[5].first=num[5].middle=num[5].last=0;
              num[8].first=num[8].middle=num[8].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
        }
        else {
          drawLine(50, '*');
          printf("\n");
          drawLine(1, '*');
          addBlank(2);
          printf("ERROR : STRIKE OR BALL CANNOT BE MINUS");
          addBlank(8);
          drawLine(1, '*');
          printf("\n");
          drawLine(1, '*');
          addBlank(2);
          printf("한 라운드 전으로 게임을 되돌립니다.");
          addBlank(11);
          drawLine(1, '*');
          printf("\n");
          round_strike[count]=round_ball[count]=0;
          startGame(NULL);
          return;
        }
      }
      else {
        drawLine(50, '*');
        printf("\n");
        drawLine(1, '*');
        addBlank(2);
        printf("ERROR : STRIKE OR BALL CANNOT BE MORE THAN 3");
        addBlank(2);
        drawLine(1, '*');
        printf("\n");
        drawLine(1, '*');
        addBlank(2);
        printf("한 라운드 전으로 게임을 되돌립니다.");
        addBlank(11);
        drawLine(1, '*');
        printf("\n");
        round_strike[count]=round_ball[count]=0;
        startGame(NULL);
        return;
      }
    }
    else {
      drawLine(50, '*');
      printf("\n");
      drawLine(1, '*');
      addBlank(2);
      printf("ERR : S+B CANNOT BE MORE THAN 6, LESS THAN 0");
      addBlank(2);
      drawLine(1, '*');
      printf("\n");
      drawLine(1, '*');
      addBlank(2);
      printf("한 라운드 전으로 게임을 되돌립니다.");
      addBlank(11);
      drawLine(1, '*');
      printf("\n");
      round_strike[count]=round_ball[count]=0;
      startGame(NULL);
      return;
    }
  }
  else if(guess_answer==NULL&&count==3) {
    addBlank(4);
    printf("PC : 369");
    addBlank(30);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    record[count].first=3;
    record[count].middle=6;
    record[count].last=9;
    drawLine(1, '*');
    addBlank(2);
    printf("스트라이크와 볼의 수를 입력해주세요.");
    addBlank(10);
    drawLine(1, '*');
    printf("\n");
    drawLine(1, '*');
    addBlank(2);
    printf("(예시) 1s 1b -> 1 1");
    addBlank(27);
    drawLine(1, '*');
    printf("\n");
    drawLine(1, '*');
    addBlank(2);
    printf("OUT은 0s 0b로 간주합니다.");
    addBlank(21);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    scanf("%d %d", &round_strike[count], &round_ball[count]);
    result_sum=round_strike[count]+round_ball[count];
    if(result_sum<=3 && result_sum>=0) {
      if(3>=round_strike[count] && 3>=round_ball[count]) {
        if(round_strike[count]>=0 && round_ball[count]>=0) {
          if(round_strike[count]==3) resultGame(LOSE);
          else if(round_strike[count]==2) {
            if(round_ball[count]==1) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[3].first, VERYHIGH);
              evaluate(&num[3].middle, LOW);
              evaluate(&num[3].last, LOW);

              evaluate(&num[6].first, LOW);
              evaluate(&num[6].middle, VERYHIGH);
              evaluate(&num[6].last, LOW);

              evaluate(&num[9].first, LOW);
              evaluate(&num[9].middle, LOW);
              evaluate(&num[9].last, VERYHIGH);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              evaluate(&num[3].first, HIGH);
              evaluate(&num[3].middle, NO);
              evaluate(&num[3].last, NO);

              evaluate(&num[6].first, NO);
              evaluate(&num[6].middle, HIGH);
              evaluate(&num[6].last, NO);

              evaluate(&num[9].first, NO);
              evaluate(&num[9].middle, NO);
              evaluate(&num[9].last, HIGH);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[3].first=num[3].middle=num[3].last=0;
              num[6].first=num[6].middle=num[6].last=0;
              num[9].first=num[9].middle=num[9].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
          else if(round_strike[count]==1) {
            if(round_ball[count]==2) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[3].first, NORMAL);
              evaluate(&num[3].middle, HIGH);
              evaluate(&num[3].last, HIGH);

              evaluate(&num[6].first, HIGH);
              evaluate(&num[6].middle, NORMAL);
              evaluate(&num[6].last, HIGH);

              evaluate(&num[9].first, HIGH);
              evaluate(&num[9].middle, HIGH);
              evaluate(&num[9].last, NORMAL);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==1) {
              evaluate(&num[3].first, LOW);
              evaluate(&num[3].middle, SOLOW);
              evaluate(&num[3].last, SOLOW);

              evaluate(&num[6].first, SOLOW);
              evaluate(&num[6].middle, LOW);
              evaluate(&num[6].last, SOLOW);

              evaluate(&num[9].first, SOLOW);
              evaluate(&num[9].middle, SOLOW);
              evaluate(&num[9].last, LOW);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              evaluate(&num[3].first, VERYLOW);
              evaluate(&num[3].middle, NO);
              evaluate(&num[3].last, NO);

              evaluate(&num[6].first, NO);
              evaluate(&num[6].middle, VERYLOW);
              evaluate(&num[6].last, NO);

              evaluate(&num[9].first, NO);
              evaluate(&num[9].middle, NO);
              evaluate(&num[9].last, VERYLOW);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[3].first=num[3].middle=num[3].last=0;
              num[6].first=num[6].middle=num[6].last=0;
              num[9].first=num[9].middle=num[9].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
          else if(round_strike[count]==0) {
            if(round_ball[count]==3) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[3].first, NO);
              evaluate(&num[3].middle, VERYHIGH);
              evaluate(&num[3].last, VERYHIGH);

              evaluate(&num[6].first, VERYHIGH);
              evaluate(&num[6].middle, NO);
              evaluate(&num[6].last, VERYHIGH);

              evaluate(&num[9].first, VERYHIGH);
              evaluate(&num[9].middle, VERYHIGH);
              evaluate(&num[9].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==2) {
              evaluate(&num[3].first, NO);
              evaluate(&num[3].middle, NORMAL);
              evaluate(&num[3].last, NORMAL);

              evaluate(&num[6].first, NORMAL);
              evaluate(&num[6].middle, NO);
              evaluate(&num[6].last, NORMAL);

              evaluate(&num[9].first, NORMAL);
              evaluate(&num[9].middle, NORMAL);
              evaluate(&num[9].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==1) {
              evaluate(&num[3].first, NO);
              evaluate(&num[3].middle, VERYLOW);
              evaluate(&num[3].last, VERYLOW);

              evaluate(&num[6].first, VERYLOW);
              evaluate(&num[6].middle, NO);
              evaluate(&num[6].last, VERYLOW);

              evaluate(&num[9].first, VERYLOW);
              evaluate(&num[9].middle, VERYLOW);
              evaluate(&num[9].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              num[3].first=NO;
              num[3].middle=NO;
              num[3].last=NO;

              num[6].first=NO;
              num[6].middle=NO;
              num[6].last=NO;

              num[9].first=NO;
              num[9].middle=NO;
              num[9].last=NO;
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[3].first=num[3].middle=num[3].last=0;
              num[6].first=num[6].middle=num[6].last=0;
              num[9].first=num[9].middle=num[9].last=0;
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
        }
        else {
          drawLine(50, '*');
          printf("\n");
          drawLine(1, '*');
          addBlank(2);
          printf("ERROR : STRIKE OR BALL CANNOT BE MINUS");
          addBlank(8);
          drawLine(1, '*');
          printf("\n");
          drawLine(1, '*');
          addBlank(2);
          printf("한 라운드 전으로 게임을 되돌립니다.");
          addBlank(11);
          drawLine(1, '*');
          printf("\n");
          round_strike[count]=round_ball[count]=0;
          startGame(NULL);
          return;
        }
      }
      else {
        drawLine(50, '*');
        printf("\n");
        drawLine(1, '*');
        addBlank(2);
        printf("ERROR : STRIKE OR BALL CANNOT BE MORE THAN 3");
        addBlank(2);
        drawLine(1, '*');
        printf("\n");
        drawLine(1, '*');
        addBlank(2);
        printf("한 라운드 전으로 게임을 되돌립니다.");
        addBlank(11);
        drawLine(1, '*');
        printf("\n");
        round_strike[count]=round_ball[count]=0;
        startGame(NULL);
        return;
      }
    }
    else {
      drawLine(50, '*');
      printf("\n");
      drawLine(1, '*');
      addBlank(2);
      printf("ERR : S+B CANNOT BE MORE THAN 6, LESS THAN 0");
      addBlank(2);
      drawLine(1, '*');
      printf("\n");
      drawLine(1, '*');
      addBlank(2);
      printf("한 라운드 전으로 게임을 되돌립니다.");
      addBlank(11);
      drawLine(1, '*');
      printf("\n");
      round_strike[count]=round_ball[count]=0;
      startGame(NULL);
      return;
    }
  }
  else if(guess_answer!=NULL) {
    int temp[3][3];
    temp[0][0]=num[guess_answer[FIRST]].first;
    temp[0][1]=num[guess_answer[FIRST]].middle;
    temp[0][2]=num[guess_answer[FIRST]].last;
    temp[1][0]=num[guess_answer[MIDDLE]].first;
    temp[1][1]=num[guess_answer[MIDDLE]].middle;
    temp[1][2]=num[guess_answer[MIDDLE]].last;
    temp[2][0]=num[guess_answer[LAST]].first;
    temp[2][1]=num[guess_answer[LAST]].middle;
    temp[2][2]=num[guess_answer[LAST]].last;
    addBlank(4);
    printf("PC : %d%d%d", guess_answer[FIRST], guess_answer[MIDDLE], guess_answer[LAST]);
    addBlank(30);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    record[count].first=guess_answer[FIRST];
    record[count].middle=guess_answer[MIDDLE];
    record[count].last=guess_answer[LAST];
    drawLine(1, '*');
    addBlank(2);
    printf("스트라이크와 볼의 수를 입력해주세요.");
    addBlank(10);
    drawLine(1, '*');
    printf("\n");
    drawLine(1, '*');
    addBlank(2);
    printf("(예시) 1s 1b -> 1 1");
    addBlank(27);
    drawLine(1, '*');
    printf("\n");
    drawLine(1, '*');
    addBlank(2);
    printf("OUT은 0s 0b로 간주합니다.");
    addBlank(21);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    scanf("%d %d", &round_strike[count], &round_ball[count]);
    result_sum=round_strike[count]+round_ball[count];
    if(result_sum<=3 && result_sum>=0) {
      if(3>=round_strike[count] && 3>=round_ball[count]) {
        if(round_strike[count]>=0 && round_ball[count]>=0) {
          if(round_strike[count]==3) resultGame(LOSE);
          else if(round_strike[count]==2) {
            if(round_ball[count]==1) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[guess_answer[FIRST]].first, VERYHIGH);
              evaluate(&num[guess_answer[FIRST]].middle, LOW);
              evaluate(&num[guess_answer[FIRST]].last, LOW);

              evaluate(&num[guess_answer[MIDDLE]].first, LOW);
              evaluate(&num[guess_answer[MIDDLE]].middle, VERYHIGH);
              evaluate(&num[guess_answer[MIDDLE]].last, LOW);

              evaluate(&num[guess_answer[LAST]].first, LOW);
              evaluate(&num[guess_answer[LAST]].middle, LOW);
              evaluate(&num[guess_answer[LAST]].last, VERYHIGH);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              evaluate(&num[guess_answer[FIRST]].first, HIGH);
              evaluate(&num[guess_answer[FIRST]].middle, NO);
              evaluate(&num[guess_answer[FIRST]].last, NO);

              evaluate(&num[guess_answer[MIDDLE]].first, NO);
              evaluate(&num[guess_answer[MIDDLE]].middle, HIGH);
              evaluate(&num[guess_answer[MIDDLE]].last, NO);

              evaluate(&num[guess_answer[LAST]].first, NO);
              evaluate(&num[guess_answer[LAST]].middle, NO);
              evaluate(&num[guess_answer[LAST]].last, HIGH);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[guess_answer[FIRST]].first=temp[0][0];
              num[guess_answer[FIRST]].middle=temp[0][1];
              num[guess_answer[FIRST]].last=temp[0][2];
              num[guess_answer[MIDDLE]].first=temp[1][0];
              num[guess_answer[MIDDLE]].middle=temp[1][1];
              num[guess_answer[MIDDLE]].last=temp[1][2];
              num[guess_answer[LAST]].first=temp[2][0];
              num[guess_answer[LAST]].middle=temp[2][1];
              num[guess_answer[LAST]].last=temp[2][2];
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
          else if(round_strike[count]==1) {
            if(round_ball[count]==2) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[guess_answer[FIRST]].first, NORMAL);
              evaluate(&num[guess_answer[FIRST]].middle, HIGH);
              evaluate(&num[guess_answer[FIRST]].last, HIGH);

              evaluate(&num[guess_answer[MIDDLE]].first, HIGH);
              evaluate(&num[guess_answer[MIDDLE]].middle, NORMAL);
              evaluate(&num[guess_answer[MIDDLE]].last, HIGH);

              evaluate(&num[guess_answer[LAST]].first, HIGH);
              evaluate(&num[guess_answer[LAST]].middle, HIGH);
              evaluate(&num[guess_answer[LAST]].last, NORMAL);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==1) {
              evaluate(&num[guess_answer[FIRST]].first, LOW);
              evaluate(&num[guess_answer[FIRST]].middle, SOLOW);
              evaluate(&num[guess_answer[FIRST]].last, SOLOW);

              evaluate(&num[guess_answer[MIDDLE]].first, SOLOW);
              evaluate(&num[guess_answer[MIDDLE]].middle, LOW);
              evaluate(&num[guess_answer[MIDDLE]].last, SOLOW);

              evaluate(&num[guess_answer[LAST]].first, SOLOW);
              evaluate(&num[guess_answer[LAST]].middle, SOLOW);
              evaluate(&num[guess_answer[LAST]].last, LOW);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              evaluate(&num[guess_answer[FIRST]].first, VERYLOW);
              evaluate(&num[guess_answer[FIRST]].middle, NO);
              evaluate(&num[guess_answer[FIRST]].last, NO);

              evaluate(&num[guess_answer[MIDDLE]].first, NO);
              evaluate(&num[guess_answer[MIDDLE]].middle, VERYLOW);
              evaluate(&num[guess_answer[MIDDLE]].last, NO);

              evaluate(&num[guess_answer[LAST]].first, NO);
              evaluate(&num[guess_answer[LAST]].middle, NO);
              evaluate(&num[guess_answer[LAST]].last, VERYLOW);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[guess_answer[FIRST]].first=temp[0][0];
              num[guess_answer[FIRST]].middle=temp[0][1];
              num[guess_answer[FIRST]].last=temp[0][2];
              num[guess_answer[MIDDLE]].first=temp[1][0];
              num[guess_answer[MIDDLE]].middle=temp[1][1];
              num[guess_answer[MIDDLE]].last=temp[1][2];
              num[guess_answer[LAST]].first=temp[2][0];
              num[guess_answer[LAST]].middle=temp[2][1];
              num[guess_answer[LAST]].last=temp[2][2];
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
          else if(round_strike[count]==0) {
            if(round_ball[count]==3) {
              // WE get 3 number all : THIS COULD BE MORE PERFECT..
              // 0~9
              evaluate(&num[guess_answer[FIRST]].first, NO);
              evaluate(&num[guess_answer[FIRST]].middle, VERYHIGH);
              evaluate(&num[guess_answer[FIRST]].last, VERYHIGH);

              evaluate(&num[guess_answer[MIDDLE]].first, VERYHIGH);
              evaluate(&num[guess_answer[MIDDLE]].middle, NO);
              evaluate(&num[guess_answer[MIDDLE]].last, VERYHIGH);

              evaluate(&num[guess_answer[LAST]].first, VERYHIGH);
              evaluate(&num[guess_answer[LAST]].middle, VERYHIGH);
              evaluate(&num[guess_answer[LAST]].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==2) {
              evaluate(&num[guess_answer[FIRST]].first, NO);
              evaluate(&num[guess_answer[FIRST]].middle, NORMAL);
              evaluate(&num[guess_answer[FIRST]].last, NORMAL);

              evaluate(&num[guess_answer[MIDDLE]].first, NORMAL);
              evaluate(&num[guess_answer[MIDDLE]].middle, NO);
              evaluate(&num[guess_answer[MIDDLE]].last, NORMAL);

              evaluate(&num[guess_answer[LAST]].first, NORMAL);
              evaluate(&num[guess_answer[LAST]].middle, NORMAL);
              evaluate(&num[guess_answer[LAST]].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==1) {
              evaluate(&num[guess_answer[FIRST]].first, NO);
              evaluate(&num[guess_answer[FIRST]].middle, VERYLOW);
              evaluate(&num[guess_answer[FIRST]].last, VERYLOW);

              evaluate(&num[guess_answer[MIDDLE]].first, VERYLOW);
              evaluate(&num[guess_answer[MIDDLE]].middle, NO);
              evaluate(&num[guess_answer[MIDDLE]].last, VERYLOW);

              evaluate(&num[guess_answer[LAST]].first, VERYLOW);
              evaluate(&num[guess_answer[LAST]].middle, VERYLOW);
              evaluate(&num[guess_answer[LAST]].last, NO);
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else if(round_ball[count]==0) {
              num[guess_answer[FIRST]].first=NO;
              num[guess_answer[FIRST]].middle=NO;
              num[guess_answer[FIRST]].last=NO;

              num[guess_answer[MIDDLE]].first=NO;
              num[guess_answer[MIDDLE]].middle=NO;
              num[guess_answer[MIDDLE]].last=NO;

              num[guess_answer[LAST]].first=NO;
              num[guess_answer[LAST]].middle=NO;
              num[guess_answer[LAST]].last=NO;
              checkGame(num, record, count++, round_strike, round_ball);
            }
            else {
              drawLine(50, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("ERROR : BALL CANNOT BE MINUS");
              addBlank(18);
              drawLine(1, '*');
              printf("\n");
              drawLine(1, '*');
              addBlank(2);
              printf("한 라운드 전으로 게임을 되돌립니다.");
              addBlank(11);
              drawLine(1, '*');
              printf("\n");
              num[guess_answer[FIRST]].first=temp[0][0];
              num[guess_answer[FIRST]].middle=temp[0][1];
              num[guess_answer[FIRST]].last=temp[0][2];
              num[guess_answer[MIDDLE]].first=temp[1][0];
              num[guess_answer[MIDDLE]].middle=temp[1][1];
              num[guess_answer[MIDDLE]].last=temp[1][2];
              num[guess_answer[LAST]].first=temp[2][0];
              num[guess_answer[LAST]].middle=temp[2][1];
              num[guess_answer[LAST]].last=temp[2][2];
              round_strike[count]=round_ball[count]=0;
              startGame(NULL);
              return;
            }
          }
        }
        else {
          drawLine(50, '*');
          printf("\n");
          drawLine(1, '*');
          addBlank(2);
          printf("ERROR : STRIKE OR BALL CANNOT BE MINUS");
          addBlank(8);
          drawLine(1, '*');
          printf("\n");
          drawLine(1, '*');
          addBlank(2);
          printf("한 라운드 전으로 게임을 되돌립니다.");
          addBlank(11);
          drawLine(1, '*');
          printf("\n");
          round_strike[count]=round_ball[count]=0;
          startGame(NULL);
          return;
        }
      }
      else {
        drawLine(50, '*');
        printf("\n");
        drawLine(1, '*');
        addBlank(2);
        printf("ERROR : STRIKE OR BALL CANNOT BE MORE THAN 3");
        addBlank(2);
        drawLine(1, '*');
        printf("\n");
        drawLine(1, '*');
        addBlank(2);
        printf("한 라운드 전으로 게임을 되돌립니다.");
        addBlank(11);
        drawLine(1, '*');
        printf("\n");
        round_strike[count]=round_ball[count]=0;
        startGame(NULL);
        return;
      }
    }
    else {
      drawLine(50, '*');
      printf("\n");
      drawLine(1, '*');
      addBlank(2);
      printf("ERR : S+B CANNOT BE MORE THAN 6, LESS THAN 0");
      addBlank(2);
      drawLine(1, '*');
      printf("\n");
      drawLine(1, '*');
      addBlank(2);
      printf("한 라운드 전으로 게임을 되돌립니다.");
      addBlank(11);
      drawLine(1, '*');
      printf("\n");
      round_strike[count]=round_ball[count]=0;
      startGame(NULL);
      return;
    }
  }
  return;
}

void checkGame(struct num *num, struct record *record, int count, int *round_strike, int *round_ball) {
  int sum=0;
  for(int i=1; i<=count; i++) {
    sum+=round_strike[i]+round_ball[i];
  }
  if(count<=3) {
    if(sum==3) {
      for(int j=0; j<=9; j++) {
        if(num[j].first==0) num[j].first=NO;
        if(num[j].middle==0) num[j].middle=NO;
        if(num[j].last==0) num[j].last=NO;
      }
    }
    int check_first, check_middle, check_last;
    check_first=num[3].first+num[6].first+num[9].first;
    check_middle=num[3].middle+num[6].middle+num[9].middle;
    check_last=num[3].last+num[6].last+num[9].last;
    if(check_first==0) {
      if(check_middle==0) {
        if(check_last==0) {
          startGame(NULL);
          return;
        }
      }
    }
  }
  else {
    int check_sum=0;
    for(int i=1; i<=3; i++) {
      check_sum+=round_strike[i]+round_ball[i];
    }
    if(check_sum<3 && sum<=3) num[0].first=num[0].middle=num[0].last=YES;
  }

  // GUESS ANSWER
  /*
  FIRST = 0, MIDDLE = 1, LAST = 2
  */
  int guess_answer[3]={10,10,10}; // To check
  int temp_first, temp_middle;
  temp_first=temp_middle=10;
  int check_overNine=0;
  int check_twice=0;
  while(check_overNine!=1) {
    for(int k=0; k<=9; k++) {
      // first
      if(k==0) continue;
      if(num[k].first==NO) continue;
      if(temp_first!=10) {
        if(k==temp_first) continue;
        if(num[k].first!=NO && num[guess_answer[FIRST]].first>=num[k].first )  guess_answer[FIRST]=k;
        continue;
      }
      if(guess_answer[FIRST]!=10) {
        if(num[k].first!=NO && num[guess_answer[FIRST]].first>num[k].first )  guess_answer[FIRST]=k;
      }
      else {
        if(num[k].first!=NO) guess_answer[FIRST]=k;
      }
    }

    for(int k=0; k<=9; k++) {
      // middle
      if(guess_answer[FIRST]==k)  continue;
      if(num[k].middle==NO) continue;
      if(temp_middle!=10) {
        if(k==temp_middle) continue;
        if(num[k].middle!=NO && num[guess_answer[MIDDLE]].middle>=num[k].middle ) {
          guess_answer[MIDDLE]=k;
        }
        continue;
      }
      if(guess_answer[MIDDLE]!=10) {
        if(num[k].middle!=NO && num[guess_answer[MIDDLE]].middle>num[k].middle ) {
          guess_answer[MIDDLE]=k;
        }
      }
      else {
        if(num[k].middle!=NO) {
          guess_answer[MIDDLE]=k;
        }
      }
    }

    for(int k=0; k<=9; k++) {
      // last
      if(guess_answer[FIRST]==k || guess_answer[MIDDLE]==k) continue;
      if(num[k].last==NO) continue;
      if(guess_answer[LAST]!=10) {
        if(num[k].last!=NO && num[guess_answer[LAST]].last>num[k].last )  guess_answer[LAST]=k;
      }
      else {
        if(num[k].last!=NO) guess_answer[LAST]=k;
      }
    }
    if(guess_answer[MIDDLE]==10) {
      temp_first=guess_answer[FIRST];
    }
    else if(guess_answer[LAST]==10) {
      if(check_twice==0) {
        temp_first=guess_answer[FIRST];
        check_twice=1;
      }
      else {
        temp_middle=guess_answer[MIDDLE];
        temp_first=10;
      }
    }
    else {
      temp_first=temp_middle=10;
      check_overNine=1;
    }
  }
  int loop=count;
  int same_cnt=0;
  int progress_code=1; // 첫번째수 부터 하니까
  int pass_code=0;
  int first_entered=0; // 첫번쨰 대입후 1로 변환
  int* recent_changed;
  recent_changed=(int*)malloc(sizeof(int)*count);
  for(int p=(count-1); p>=0; p--) {
    recent_changed[p]=10;
  }

while(loop!=0) {
  unsigned int guess_num = guess_answer[FIRST]*100+guess_answer[MIDDLE]*10+guess_answer[LAST];
  unsigned int record_num = record[loop].first*100+record[loop].middle*10+record[loop].last;
    if(guess_num==record_num) {
      if(progress_code==1) {
        for(int i=9; i!=0; i--) {
          if(i==record[loop].first) continue;
          if(i==record[loop].middle) continue;
          if(i==record[loop].last) continue;
          if(num[i].first==NO) continue;
          if(first_entered==0) {
            guess_answer[FIRST]=i;
            recent_changed[same_cnt]=i;
            first_entered=1;
          }
          if(pass_code==0) {
            if(num[guess_answer[FIRST]].first>num[i].first) {
              guess_answer[FIRST]=i;
              recent_changed[same_cnt]=i;
            }
          }
          else {
            if(num[guess_answer[FIRST]].first>=num[i].first) {
              guess_answer[FIRST]=i;
              recent_changed[same_cnt]=i;
            }
          }
        }
        for(int j=same_cnt; j!=0; j--) {
          if(guess_answer[FIRST]==recent_changed[same_cnt] || recent_changed[same_cnt]==10 ) {
            progress_code=2; // 2번쨰수로
            same_cnt=0;
            first_entered=0;
            free(recent_changed);
            recent_changed=(int*)malloc(sizeof(int)*count);
            for(int p = (count - 1); p>=0; p--) {
              recent_changed[p]=10;
            }
            break;
          }
        }
        if(progress_code==1)
          same_cnt++;
        loop=count;
        continue;
      }
      if(progress_code==2) {
        for(int i=0; i<10; i++) {
          if(i==record[loop].first) continue;
          if(i==record[loop].middle) continue;
          if(i==record[loop].last) continue;
          if(num[i].middle==NO) continue;
          if(first_entered==0) {
            guess_answer[MIDDLE]=i;
            recent_changed[same_cnt]=i;
            first_entered=1;
          }
          if(pass_code==0) {
            if(num[guess_answer[MIDDLE]].middle>num[i].middle) {
              guess_answer[MIDDLE]=i;
              recent_changed[same_cnt]=i;
            }
          }
          else {
            if(num[guess_answer[MIDDLE]].middle>=num[i].middle) {
              guess_answer[MIDDLE]=i;
              recent_changed[same_cnt]=i;
            }
          }
        }
        for(int j=same_cnt; j!=0; j--) {
          if(guess_answer[MIDDLE]==recent_changed[same_cnt] || recent_changed[same_cnt]==10) {
            progress_code=3; // 3번쨰수로
            same_cnt=0;
            first_entered=0;
            free(recent_changed);
            recent_changed=(int*)malloc(sizeof(int)*count);
            for(int p = (count - 1); p>=0; p--) {
              recent_changed[p]=10;
            }
            break;
          }
        }
        if(progress_code==2)
          same_cnt++;
        loop=count;
        continue;
      }
      if(progress_code==3) {
        for(int i=0; i<10; i++) {
          if(i==record[loop].first) continue;
          if(i==record[loop].middle) continue;
          if(i==record[loop].last) continue;
          if(num[i].last==NO) continue;
          if(first_entered==0) {
            guess_answer[LAST]=i;
            recent_changed[same_cnt]=i;
            first_entered=1;
          }
          if(pass_code==0) {
            if(num[guess_answer[LAST]].last>num[i].last) {
              guess_answer[LAST]=i;
              recent_changed[same_cnt]=i;
            }
          }
          else {
            if(num[guess_answer[LAST]].last>=num[i].last) {
              guess_answer[LAST]=i;
              recent_changed[same_cnt]=i;
            }
          }
        }
        for(int j=same_cnt; j!=0; j--) {
          if(guess_answer[LAST]==recent_changed[same_cnt] || recent_changed[same_cnt]==10) {
            progress_code=1; 
            pass_code=1;
            same_cnt=0;
            first_entered=0;
            free(recent_changed);
            recent_changed=(int*)malloc(sizeof(int)*count);
            for(int p = (count - 1); p>=0; p--) {
              recent_changed[p]=10;
            }
            break;
          }
        }
        if(progress_code==3)
          same_cnt++;
        loop=count;
        continue;
      }
      if(progress_code==0) {
        printf("ERROR OCCURED\n");
      }
    }
    loop--;
}
  free(recent_changed);
  startGame(guess_answer);
  return;
}

void resultGame(int result_code) {
  drawLine(50, '*');
  printf("\n");
  if(result_code==WIN) {
    drawLine(1, '*');
    addBlank(2);
    printf("YOU ARE VICTORY");
    addBlank(31);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    return;
  }
  else if(result_code==LOSE) {
    drawLine(1, '*');
    addBlank(2);
    printf("YOU ARE LOSE");
    addBlank(34);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    return;
  }
  else {
    drawLine(1, '*');
    addBlank(2);
    printf("an ERROR OCCURED #%d\n", result_code);
    addBlank(27);
    drawLine(1, '*');
    printf("\n");
    drawLine(50, '*');
    printf("\n");
    return;
  }
  return;
}

void evaluate(int *num, int result) {
  if(*num!=NO) {
    *num=result;
  }
}
void drawLine(int count, char word) {
  while(count--) {
    printf("%c", word);
  }
  return;
}
void addBlank(int count) {
  while(count--) {
    printf(" ");
  }
  return;
}
