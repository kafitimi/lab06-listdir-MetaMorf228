#include "windows.h"
#include <stdio.h>
#pragma warning( disable : 4996)

static int count;



int main() {
    	wchar_t s[512];              	// ������� �����
    	GetCurrentDirectory(512, s);	// �������� ������� �����
    	wprintf(L"Starting in: %s\n", s);

		HANDLE hFind;                   	// ����� ������
		WIN32_FIND_DATA fileinfo;            	// ��������� ������
		hFind = FindFirstFile(L"*", &fileinfo);   // ����� ������ ����
		wprintf(L"%s\n", fileinfo.cFileName);
    	count = 0;                  	// �������� ������� ������    	

        //dfs();                     	// ��������� ����� � �������
		do {
			count++;
			if (count > 2)
				wprintf(L"file #%d is <%s>\n", count-2, fileinfo.cFileName);

			// ...
			// ����� ����� ����� � �������
		} while (FindNextFile(hFind, &fileinfo) != 0);
		FindClose(hFind);
    	wprintf(L"File count = %d\n", count-2);
    	return 0;
}


/*void dfs() {
	HANDLE hFind;                   	// ����� ������
	WIN32_FIND_DATA res;            	// ��������� ������

	CHAR dir[] = ".\\*";
	hFind = FindFirstFile(dir, &res);   // ����� ������ ����

	do {
    	count++; // ��������� ����� �� ���������??
    	_tprintf(TEXT("file #%d is <%s>\n"), count, res.cFileName);

    	// ...
    	// ����� ����� ����� � �������
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
}
*/
