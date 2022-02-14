#include <bits/stdc++.h>
using namespace std;

struct Dictionary
{
    string word;
    int numbers;
};

int main()
{
    string given_str = "";
    fstream newfile;
    int out_numbers;
    newfile >> out_numbers;
    newfile.open("tpoint.txt");
    if (newfile.is_open())
    {
        string tp;

        while (getline(newfile, tp))
        {
            given_str += tp;
        }
        newfile.close();
    }

    bool is_write, find_word, bubble_sort, search_word, split_string, output = false;
    string word_to_search = "";
    string stop_words[3] = {"the", "for", "in"};
    Dictionary *dict = new Dictionary[1000000];
    int finded_word_index = -1;
    int dict_i = 0, length = 0, pos = 0;

    string token1;

    split_string = true;
    goto func_split_string;

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
                    dict[finded_word_index].numbers++;
                    finded_word_index = -1;
                }
                else if (finded_word_index == -2)
                {
                }
                else
                {
                    dict[dict_i] = (Dictionary){token1, 1};
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
                if (dict[j].numbers < dict[j + 1].numbers)
                {
                    Dictionary temp = {dict[j].word, dict[j].numbers};
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
        if (i < out_numbers)
        {
            if (dict[i].numbers > 0)
                cout << dict[i].word << " " << dict[i].numbers << endl;
            i++;
            goto func_output_inner;
        }
    }

func_find_word:
    if (find_word)
    {
        int n = 0;

    func_find_stop_word:
        if (stop_words[n] == token1)
        {
            finded_word_index = -2;
            find_word = false;
            goto back_find_word;
        }
        else if (n < 3)
        {
            n++;
            goto func_find_stop_word;
        }
        else
        {
            n = 0;
            goto func_find_word_inner;
        }

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