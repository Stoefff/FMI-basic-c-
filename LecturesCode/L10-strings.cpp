/*
Примерна програма за демонстрация на символни низове към курса УП (2017)
Работа със символни низове:
    дължина, копиране, сравняване, дублиране
    броене на всички думи в текст
    извличане на думи
*/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::nothrow;

// Намира дължината на низ
size_t strlen(const char* text)
{
    size_t len = 0;
    while (text[len])
        ++len;
    return len;
}

// копира низа src в паметта сочена от dest.
void strcpy(char* dest, const char* src)
{
    int pos = 0;
    while(src[pos])
    {
        dest[pos] = src[pos];
        ++pos;
    }
    dest[pos] = '\0';
}

// Указателна версия на копирането
void strcpyPtr(char* dest, const char* src)
{
    while (*dest++ = *src++)
        ;
}

// Сравнява два низа лексикографски.
// Връща 0 ако са равни, отрицателно число ако първия е по-малък
// и положително ако втория е по-малък.
int strcmp(const char* text1, const char* text2)
{
    while (*text1 && *text1 == *text2)
    {
        ++text1;
        ++text2;
    }
    return *text1 - *text2;
}

char* strdup(const char* text)
{
    char* newtext = new(nothrow) char[strlen(text)+1];
    if(newtext)
    {
        strcpy(newtext, text);
    }
    return newtext;
}

bool isWordLetter(char c)
{
    return (c >= 'A' && c <= 'Z') ||
           (c >= 'a' && c <= 'z') ||
           (c >= '0' && c <= '9') ||
           c == '_';
}


// Намира броя думи в текст.
// Дума е последователност от букви или цифри оградена от различен символ
int wordCount(const char* text)
{
    int cnt = 0;
    while (*text)
    {
        while (*text && !isWordLetter(*text))   // прескачаме до начало на дума
        {
            ++text;
        }
        if (*text)
        {
            ++cnt;                              // ако такава има я преброяваме
        }
        while (isWordLetter(*text))             // и прескачаме до края ѝ
        {
            ++text;
        }
    }
    return cnt;
}


// Извлича всички думи от текст в масив.
// Заделя памет за масива и за всяка една дума.
// Връща броя на думите
int extractWords(const char* text, char *** wordsPtr)
{
    int cnt = wordCount(text);  // намираме броя на думите
    *wordsPtr = new(nothrow) char*[cnt];    // и заделяме памет за тях
    if (!*wordsPtr) return 0;

    for (int i = 0; i < cnt; ++i)           // за всяка една дума
    {
        // намираме началото ѝ
        while (*text && !isWordLetter(*text))
            ++text;
        if (*text)      // ако има дума
        {
            const char* start = text;
            while (isWordLetter(*text))     // намираме края ѝ
                ++text;

            int len = text - start;         // и съответно дължината
            (*wordsPtr)[i] = new(nothrow) char[len+1];      // заделя памет за думата
            if (!(*wordsPtr)[i])
            {
                cout << "No memory for word " << i;
                return i;           // Връщаме по-малък брой - реално извлечените думи
                /*
                // Алтернативен подход с освобождаване на цялата заделена памет
                for (--i; i >= 0; --i)
                    delete[](*wordsPtr)[i];
                delete[] (*wordsPtr);
                *wordsPtr = NULL;
                return 0;
                */
            }
            for (int pos = 0; pos < len; ++pos)             // копира думата
                (*wordsPtr)[i][pos] = start[pos];
            (*wordsPtr)[i][len] = '\0';                     // и поставя терминал накрая
        }
    }
    return cnt;
}

void wordTest(const char* text)
{
    char ** words;
    int cnt = extractWords(text, &words);
    int properCnt = wordCount(text);
    if (!words)
    {
        cout << "Memory problem!" << endl;
        return;
    }
    if (cnt != properCnt)
    {
        cout << "Memory problem - not all words extracted!";
    }

    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i)
        cout << words[i] << endl;

    for (int i = 0; i < cnt; ++i)
        delete[] words[i];
    delete[] words;
}

// Проверява дали даден текст се среща в друг.
// Връща указател към първото срещане или NULL
// Реализира наивен, квадратичен алгоритъм
const char* strstr(const char* where, const char* what)
{
    size_t whatLen = strlen(what);
    size_t pos;
    const char* whereEnd = where + strlen(where);

    while (where+whatLen <= whereEnd)
    {
        for (pos = 0; pos < whatLen; ++pos)
        {
            if (where[pos] != what[pos])
            {
                break;
            }
        }
        if (!what[pos]) return where;
        ++where;
    }
    return NULL;
}

int main()
{
    const char* text = "C++ is cool and pointers are cool too!";

    char* copy = strdup(text);
    cout << text;
    delete[] copy;


/*
    size_t len = strlen(text);
    cout << len << endl;

    char* buff = new(nothrow) char[len+1];
    if (!buff)
    {
        cout << "memory problem!" << endl;
        return 1;
    }

    strcpyPtr(buff, text);
    cout << buff << endl;
    cout << strcmp(buff, text) << endl;
    buff[len-1] = '.';
    cout << strcmp(buff, text) << endl;

    delete[] buff;
*/
    cout << strstr(text, "too!") << endl;

//    wordTest(text);
    return 0;
}
