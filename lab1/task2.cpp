#include <bits/stdc++.h>
using namespace std;

struct Dictionary
{
    string word;
    int numbers;
    int pages[100];
};

int main()
{
    string given_str = "";

    bool is_write, find_word, bubble_sort, search_word, split_string, output = false;
    string word_to_search = "";
    string stop_words[3] = {"the", "for", "in"};
    Dictionary *dict = new Dictionary[1000000];
    int finded_word_index = -1;
    int number_of_page = 1, number_of_line = 1;
    int dict_i = 0, length = 0, pos = 0;

    string token1;
    string tp;

    fstream newfile;
    int out_numbers;
    newfile >> out_numbers;
    newfile.open("tpoint.txt");
    if (newfile.is_open())
    {
    func_split_string_outer:
        if (getline(newfile, tp))
        {

            given_str = (tp);
            given_str += ' ';
            split_string = true;
            goto func_split_string;

        back_func_split_string:
            string given_str = "";
            pos = 0;
            if (number_of_line == 45)
            {
                number_of_line = 0;
                number_of_page++;
            }
            goto func_split_string_outer;
        }
        newfile.close();
    }

func_split_string:
    if (split_string)
    {
        pos = 0;
    func_split_string_inner:
        if (given_str[pos] != '\0')
        {
            if ((given_str[pos] > 64 && given_str[pos] < 91) || (given_str[pos] > 96 && given_str[pos] < 123))
            {

                token1 += given_str[pos];
                is_write = true;
            }

            else if (is_write)
            {
                find_word = true;
                goto func_find_word;

            back_find_word:
                if (finded_word_index != -1)
                {
                    if (dict[finded_word_index].numbers != 0)
                    {

                        dict[finded_word_index].pages[dict[finded_word_index].numbers] = number_of_page;
                        dict[finded_word_index].numbers++;
                    }
                    if (dict[finded_word_index].numbers == 100)
                    {
                        dict[finded_word_index].numbers = 0;
                    }
                    finded_word_index = -1;
                }

                else
                {
                    dict[dict_i] = (Dictionary){token1, 1, {number_of_page}};
                    dict_i++;
                }
                token1 = "";
                is_write = false;
            }
            else
            {
                token1 = "";
            }

            pos++;
            goto func_split_string_inner;
        }
        else
        {
            split_string = false;
            goto back_func_split_string;
        }
    }

    bubble_sort = true;
func_bubble_sort:
    if (bubble_sort)
    {
        int n = dict_i;
        int i = 0;

    func_bubble_sort_outer:
        if (i < n)
        {
            int j = 0;

        func_bubble_sort_inner:
            if (j < n - i - 1)
            {
                if (dict[j].word > dict[j + 1].word)
                {
                    Dictionary temp = dict[j];
                    dict[j] = dict[j + 1];
                    dict[j + 1] = temp;
                }

                j++;
                goto func_bubble_sort_inner;
            }

            i++;
            goto func_bubble_sort_outer;
        }
        bubble_sort = false;
    }

    output = true;
func_output:
    if (output)
    {
        int i = 0;
    func_output_inner:
        if (i < dict_i)
        {
            if (dict[i].numbers > 0)
            {
                cout << dict[i].word << " - ";
                int j = 0;
            func_output_pages:
                if (j < dict[i].numbers)
                {
                    if (j == dict[i].numbers - 1)
                    {
                        cout << dict[i].pages[j] << endl;
                    }
                    else{
                        if(dict[i].pages[j] == dict[i].pages[j+1]){
                            j++;
                    goto func_output_pages;
                        }
                    cout << dict[i].pages[j] << ", ";
                    }
                    j++;
                    goto func_output_pages;
                }
            }
            i++;
            goto func_output_inner;
        }
    }

func_find_word:
    if (find_word)
    {
        int n = 0;

    func_find_word_inner:
        if (dict[n].word == token1)
        {
            finded_word_index = n;
            find_word = false;
            goto back_find_word;
        }
        else if (n < dict_i)
        {
            n++;
            goto func_find_word_inner;
        }
        else
        {
            int finded_word_index = -1;
            find_word = false;
            goto back_find_word;
        }
    }
    return 0;
}