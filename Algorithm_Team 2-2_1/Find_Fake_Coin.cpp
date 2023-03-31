#include <stdio.h>

int weight(int groupA_first, int groupA_last, int groupB_first, int groupB_last, int fcoin)
{
	if (groupA_first <= fcoin && fcoin <= groupA_last)
		return -1;//코인이 좌측에 있으면 -1반환
	if (groupB_first <= fcoin && fcoin <= groupB_last)
		return 1; //코인이 우측에 있으면 1반환
	else
		return 0;
}

int find_fake_coin(int start, int end)
{
	if (start == end)
		return start;

	int fake_coin = 500; //가짜 동전의 위치 
	int a_first, a_end, mid, b_first, b_end;

	mid = (end - start + 1) / 2;

	a_first = start;
	a_end = start + mid - 1;
	b_first = start + mid;
	b_end = b_first + mid - 1;


	if (weight(a_first, a_end, b_first, b_end, fake_coin) == -1) { //코인이 좌측에 있음
		return find_fake_coin(a_first, a_end);
	}
	else if (weight(a_first, a_end, b_first, b_end, fake_coin) == 1) { //코인이 우측에 있음
		return find_fake_coin(b_first, b_end);
	}
	else {
		return end;
	}

}

int main()
{
	int coins = 1024; //동전
	printf("fake coin의 위치는: %d입니다.", find_fake_coin(0, coins - 1));

	return 0;
}
