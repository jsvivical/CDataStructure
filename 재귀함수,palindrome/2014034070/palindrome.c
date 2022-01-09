#include <stdio.h>
#include <string.h>

int palindrom( char *str, int left, int right)
{
	if (left == right) return 1; //���̽� ���̽�
	if (left == right - 1 && str[left] == str[right]) return 1; //���̽����̽� : ���ڿ� ���� ¦���� ��
	if (left < right) return palindrom(str, left + 1, right -1); //���ʷ����̽�

	else return 0;
		
}


int main()
{
	char word[20];
	int num;
	int start = 0;
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", word);


	num = palindrom(word, start, strlen(word) - 1 );


	if(num == 1) printf("palindrom\n");
	else printf("not palindrom\n");



	return 0;
}