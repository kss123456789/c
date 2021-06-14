#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void compare(char *a, char *b);


int main(int argc, string argv[])
{
    FILE *file;
    long lsize;
    char *buffer;
    long result;

    file = fopen("phonebook.txt", "a+");
    if (file == NULL)
    {
        fputs("File error", stderr);
        exit(1);
    }

    // fseek으로 file의 끝까지 읽어들인뒤 ftell을 통해 파일의 크기를 측정한다. 이후 rewind를 사용해 파일의 시작지점으로 돌아간다.
    fseek(file, 0, SEEK_END);
    lsize = ftell(file);
    rewind(file);

    // 전체 파일의 내용을 받을 수 있을 정도의 크기로 메모리를 할당한다.
    buffer = malloc(lsizhele);
    if (buffer == NULL)
    {
        fputs("Memory error", stderr);
        exit(2);
    }

    // 그 파일의 내용을 버퍼에 저장한다.
    result = fread(buffer, 1, lsize, file);
    if (result != lsize)
    {
        fputs("Reading error", stderr);
        exit(3);
    }
    //이름을 묻고 같은 값을 찾음
    if(argc == 2 && strcmp(argv[1], "find") == 0)
    {
        char *name = get_string("Name : ");
        compare(name, buffer);
        return 0;
    }
    //이름과 번호 추가
    if(argc == 2 && strcmp(argv[1], "add") == 0)
    {
        char *name = get_string("name : ");
        char *number = get_string("number : ");
        fprintf(file, "%s,%s\n", name, number);
        printf("success\n");
    }
    //현재 find 커맨드를 사용했을때도 아래 문구가 출력되는 문제가 있어 우선 find 관련에 return을 사용하여 대충 해결해 두었다 원인은 뭘까?
    else
    {
        printf("Worng command! (Please type add or find)\n");
    }


    fclose(file);
    free(buffer);
    return 0;
}

//같은 값을 찾는 과정
void compare(char *a, char *b)
{
    char *search = strpbrk(b, a);
    if (search)
    {
        int l = strlen(a);
        if (strncmp(search, a, l) == 0)
        {
            printf("number : ");
            for (int i = 1; i < 100; i++)
            {
                printf("%c", *(search + l + i));
                if (*(search + l + i) == '\n')
                {
                    return;
                }
            }
        }
    }
    else
    {
        printf("not found\n");
        return;
    }
    compare(a, b + 1);
}
