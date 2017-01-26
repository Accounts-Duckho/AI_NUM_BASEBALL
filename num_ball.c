#include <stdio.h>
#include "game.h"
// WIN = 0, LOSE = 1
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
  printf("숫자야구 대결!\n");
  printf("정해진 라운드까지 컴퓨터가 맞추지 못하면 당신의 승리\n");
  printf("그 안에 맞추면 당신의 패배\n");
  printf("숫자는 102~987 사이 중복없는 숫자들의 조합으로 해야합니다.\n");
  loadGame();
  return 0;
}
void loadGame(void) {
  int choice_start;
  printf(" < 게임을 시작하려면 1번 종료하려면 2번을 입력해주세요. >\n");
  scanf("%d", &choice_start);
  if(choice_start==1) {
    startGame(NULL);
  }
  else if(choice_start==2) {
    return;
  }
  else {
    loadGame();
    return;
  }
  return;
}
void startGame(int* guess_answer) {
  static struct num num[10];
  static int round_strike[15]={0};
  static int round_ball[15]={0};
  static struct record record[50];
  static int count=1;
  int result_sum;
  printf("[%dR]\n", count);
  if(count==1) {
    printf(" PC : 147 \n");
    record[count].first=1;
    record[count].middle=4;
    record[count].last=7;
    printf(" 스트라이크와 볼의수를 입력해주세요.\n");
    printf("(예시) 1s 1b -> 1 1\n");
    printf("OUT은 0s 0b로 간주합니다.\n");
    scanf("%d %d", &round_strike[count], &round_ball[count]);
    result_sum=round_strike[count]+round_ball[count];
    if(result_sum<=6 && result_sum>=0) {
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
          printf("an ERROR OCCURED : STRIKE OR BALL CANNOT BE MINUS\n");
          round_strike[count]=round_ball[count]=0;
          startGame(NULL);
          return;
        }
      }
      else {
        printf("an ERROR OCCURED : STRIKE OR BALL CANNOT BE MORE THAN 3\n");
        round_strike[count]=round_ball[count]=0;
        startGame(NULL);
        return;
      }
    }
    else {
      printf("an ERROR OCCURED : STRIKE+BALL CANNOT BE MORE THAN 6, LESS THAN 0\n");
      round_strike[count]=round_ball[count]=0;
      startGame(NULL);
      return;
    }
  }
  else if(count==2) {
    printf(" PC : 258 \n");
    record[count].first=2;
    record[count].middle=5;
    record[count].last=8;
    printf(" 스트라이크와 볼의수를 입력해주세요.\n");
    printf("(예시) 1s 1b -> 1 1\n");
    printf("OUT은 0s 0b로 간주합니다.\n");
    scanf("%d %d", &round_strike[count], &round_ball[count]);
    result_sum=round_strike[count]+round_ball[count];
    if(result_sum<=6 && result_sum>=0) {
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
          printf("an ERROR OCCURED : STRIKE OR BALL CANNOT BE MINUS\n");
          round_strike[count]=round_ball[count]=0;
          startGame(NULL);
          return;
        }
      }
      else {
        printf("an ERROR OCCURED : STRIKE OR BALL CANNOT BE MORE THAN 3\n");
        round_strike[count]=round_ball[count]=0;
        startGame(NULL);
        return;
      }
    }
    else {
      printf("an ERROR OCCURED : STRIKE+BALL CANNOT BE MORE THAN 6, LESS THAN 0\n");
      round_strike[count]=round_ball[count]=0;
      startGame(NULL);
      return;
    }
  }
  else if(guess_answer==NULL&&count==3) {
    printf(" PC : 369 \n");
    record[count].first=3;
    record[count].middle=6;
    record[count].last=9;
    printf(" 스트라이크와 볼의수를 입력해주세요.\n");
    printf("(예시) 1s 1b -> 1 1\n");
    printf("OUT은 0s 0b로 간주합니다.\n");
    scanf("%d %d", &round_strike[count], &round_ball[count]);
    result_sum=round_strike[count]+round_ball[count];
    if(result_sum<=6 && result_sum>=0) {
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
          printf("an ERROR OCCURED : STRIKE OR BALL CANNOT BE MINUS\n");
          round_strike[count]=round_ball[count]=0;
          startGame(NULL);
          return;
        }
      }
      else {
        printf("an ERROR OCCURED : STRIKE OR BALL CANNOT BE MORE THAN 3\n");
        round_strike[count]=round_ball[count]=0;
        startGame(NULL);
        return;
      }
    }
    else {
      printf("an ERROR OCCURED : STRIKE+BALL CANNOT BE MORE THAN 6, LESS THAN 0\n");
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
    printf(" PC : %d%d%d \n", guess_answer[FIRST], guess_answer[MIDDLE], guess_answer[LAST]);
    record[count].first=guess_answer[FIRST];
    record[count].middle=guess_answer[MIDDLE];
    record[count].last=guess_answer[LAST];
    printf(" 스트라이크와 볼의수를 입력해주세요.\n");
    printf("(예시) 1s 1b -> 1 1\n");
    printf("OUT은 0s 0b로 간주합니다.\n");
    scanf("%d %d", &round_strike[count], &round_ball[count]);
    result_sum=round_strike[count]+round_ball[count];
    if(result_sum<=6 && result_sum>=0) {
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
              printf("an ERROR OCCURED : BALL CANNOT BE MINUS\n");
              printf("한 라운드 전으로 게임을 되돌립니다.\n");
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
          printf("an ERROR OCCURED : STRIKE OR BALL CANNOT BE MINUS\n");
          round_strike[count]=round_ball[count]=0;
          startGame(NULL);
          return;
        }
      }
      else {
        printf("an ERROR OCCURED : STRIKE OR BALL CANNOT BE MORE THAN 3\n");
        round_strike[count]=round_ball[count]=0;
        startGame(NULL);
        return;
      }
    }
    else {
      printf("an ERROR OCCURED : STRIKE+BALL CANNOT BE MORE THAN 6, LESS THAN 0\n");
      round_strike[count]=round_ball[count]=0;
      startGame(NULL);
      return;
    }
  }
  return;
}

void checkGame(struct num *num, struct record *record, int count, int *round_strike, int *round_ball) {
  int sum=0;
  // OUT NUMBER CHECK
  for(int p=0; p<=9; p++) {
    printf("(%d) %d%d%d\n",p, num[p].first, num[p].middle, num[p].last);
  }
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
    if(sum<=3) num[0].first=num[0].middle=num[0].last=YES;
  }

  // GUESS ANSWER
  /*
  FIRST = 0, MIDDLE = 1, LAST = 2
  */
  int guess_answer[3]={10,10,10}; // To check
  for(int k=0; k<=9; k++) {
    // first
    if(k==0) continue;
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
    if(guess_answer[LAST]!=10) {
      if(num[k].last!=NO && num[guess_answer[LAST]].last>num[k].last )  guess_answer[LAST]=k;
    }
    else {
      if(num[k].last!=NO) guess_answer[LAST]=k;
    }
  }
  int enter_code=0; // enter_code 1: middle, 2: last

  for(int q=1; q<=count; q++) {
    if(record[q].first==guess_answer[FIRST]) {
      if(record[q].middle==guess_answer[MIDDLE]) {
        if(record[q].last==guess_answer[LAST]) {
          for(int k=1; k<=9; k++) {
            // first
            printf("(%d)[%d]%d %d\n",q, k, record[q].first, guess_answer[FIRST]);
            if(k==record[q].first) continue;
            if(guess_answer[FIRST]!=record[q].first ) {
              if(num[k].first!=NO && num[guess_answer[FIRST]].first>num[k].first ) {
                guess_answer[FIRST]=k;
                printf("dd\n");
              }
            }
            else if(k==9 && num[9].first==NO) {
              enter_code=1;
            }
            else {
              if(num[k].first!=NO && record[q].first<k) {
                int temp=guess_answer[FIRST];
                guess_answer[FIRST]=k;
                for(int s=1; s<=q;s++) {
                  if(record[s].first==guess_answer[FIRST]) {
                    if(record[s].middle==guess_answer[MIDDLE]) {
                      if(record[s].last==guess_answer[LAST]) {
                        guess_answer[FIRST]=temp;
                        break;
                      }
                    }
                  }
                }
              }
            }
          if(enter_code==1) {
            for(int k=0; k<=9; k++) {
              // middle
              if(guess_answer[FIRST]==k) continue;
              if(k==record[q].middle) continue;
              if(guess_answer[MIDDLE]!=record[q].middle) {
                if(num[k].middle!=NO && num[guess_answer[MIDDLE]].middle>num[k].middle ) {
                  guess_answer[MIDDLE]=k;
                }
              }
              else if(k==9) {
                enter_code=2;
              }
              else {
                if(num[k].middle!=NO) {
                  guess_answer[MIDDLE]=k;
                }
              }
            }
          }
          if(enter_code==2) {
            for(int k=0; k<=9; k++) {
              // last
              if(guess_answer[FIRST]==k || guess_answer[MIDDLE]==k) continue;
              if(k==record[q].last) continue;
              if(guess_answer[LAST]!=record[q].last) {
                if(num[k].last!=NO && num[guess_answer[LAST]].last>num[k].last )  guess_answer[LAST]=k;
              }
              else {
                if(num[k].last!=NO) guess_answer[LAST]=k;
              }
            }
          }
          }
        }
      }
    }
  }
  startGame(guess_answer);
  return;
}

void resultGame(int result_code) {
  if(result_code==WIN) {
    printf("YOU ARE VICTORY\n");
    return;
  }
  else if(result_code==LOSE) {
    printf("YOU ARE LOSE\n");
    return;
  }
  else {
    printf("an ERROR OCCURED #%d\n", result_code);
    return;
  }
  return;
}

void evaluate(int *num, int result) {
  if(*num!=NO) {
    *num=result;
  }
}
