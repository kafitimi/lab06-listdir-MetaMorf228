#include "windows.h"
#include <stdio.h>
#pragma warning( disable : 4996)

static int count;



int main() {
    	wchar_t s[512];              	// текущая папка
    	GetCurrentDirectory(512, s);	// получить текущую папку
    	wprintf(L"Starting in: %s\n", s);

		HANDLE hFind;                   	// номер поиска
		WIN32_FIND_DATA fileinfo;            	// результат поиска
		hFind = FindFirstFile(L"*", &fileinfo);   // найти первый файл
		wprintf(L"%s\n", fileinfo.cFileName);
    	count = 0;                  	// обнулить счетчик файлов    	

        //dfs();                     	// запустить обход в глубину
		do {
			count++;
			if (count > 2)
				wprintf(L"file #%d is <%s>\n", count-2, fileinfo.cFileName);

			// ...
			// здесь будет обход в глубину
		} while (FindNextFile(hFind, &fileinfo) != 0);
		FindClose(hFind);
    	wprintf(L"File count = %d\n", count-2);
    	return 0;
}


/*void dfs() {
	HANDLE hFind;                   	// номер поиска
	WIN32_FIND_DATA res;            	// результат поиска

	CHAR dir[] = ".\\*";
	hFind = FindFirstFile(dir, &res);   // найти первый файл

	do {
    	count++; // некоторые файлы не считаются??
    	_tprintf(TEXT("file #%d is <%s>\n"), count, res.cFileName);

    	// ...
    	// здесь будет обход в глубину
	} while (FindNextFile(hFind, &res) != 0);
	FindClose(hFind);
}
*/
