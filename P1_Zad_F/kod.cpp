//Kajetan Ozog
#include <string>
using namespace std;


string FormatujNapis(string str, string one, string two, string three)
{
    string nneeww = "";
    char operation;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '{')
        {
            operation = str[i + 1];
            if (operation == 'p')
            {
                int number = str[i + 3];
                number -= 48;
                for(int j = 0; j < number; j++)
                {
                    nneeww+= str[i + 5];
                }
                i += 6;
            }
            else if (operation == 'u')
            {
                int number = str[i + 3];
                number -= 48;
                for(int j = 0; j < number; j++)
                {
                    i++;
                }
                i += 4;
            }
            else if (operation == 'U')
            {
                int number = str[i + 3];
                number -= 48;
                nneeww.resize((nneeww.size() - number));
                i += 4;
            }
            else if (operation == 'w')
            {
                char number = str[i + 3];
                if (number == '1')
                {
                    nneeww += one;
                }
                else if (number == '2')
                {
                    nneeww += two;
                }
                else if (number == '3')
                {
                    nneeww += three;
                }
                i += 4;
            }
            else if (operation == 'W')
            {
                char number = str[i + 3];
                string added_string;
                if (number == '1')
                {
                    added_string = one;
                }
                else if (number == '2')
                {
                    added_string = two;
                }
                else if (number == '3')
                {
                    added_string = three;
                }
                int m = str[i + 5];
                m -= 48;
                if (m >= added_string.size())
                {
                    nneeww += added_string;
                    for (int j = 0; j < (m - added_string.size()); j++)
                    {
                        nneeww += " ";
                    }
                }
                else
                {
                    for(int j = 0; j < m; j++)
                    {
                        nneeww += added_string[j];
                    }
                }
                i += 6;
            }
        }
        else
        {
            nneeww += str[i];
        }
    }
    return nneeww;
}


string NajwiekszeSlowo(string str)
{
    string max = "";
    string sub_str = "";
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] ==  ' ')
        {
            if(sub_str > max)
            {
                max = sub_str;
            }
            sub_str = "";
        }
        else
        {
            sub_str += str[i];
        }
        if(i == (str.size() - 1))
        {
            if(sub_str > max)
            {
                max = sub_str;
            }
        }
    }
    return max;
}


string NormalizujNapis(string str)
{
    string nneeww = "";
    int size = str.size();
    while(str[size -1] == ' ')
    {
        size--;
    }
    int i = 0;
    while(str[i] == ' ')
    {
        i++;
    }
    for(int j = i; j < (size -1); j++)
    {
        if((str[j] == ' ') && ((str[j+1] == ' ') || ((str[j+1] == ',') || (str[j+1] == '.'))))
        {
            int a;
        }
        else
        {
            nneeww += str[j];
        }
        if ((str[j] == '.' || str[j] == ',') && (str[j+1] != ' '))
        {
            nneeww += " ";
        }
    }
    nneeww += str[size -1];
    return nneeww;
}


string UsunSlowo(string str, int number)
{
    string nneeww = "";
    int j = 0;
    int num_of_word = 1;
    while(str[j] == ' ')
    {
        nneeww += str[j];
        j++;
    }
    for(int i = j; i < str.size(); i++)
    {
        if(str[i] == ' ')
        {
            while(str[i] == ' ')
            {
                nneeww += " ";
                i++;
            }
            i--;
            num_of_word++;

        }
        if(num_of_word != number)
        {
            nneeww += str[i];
        }
    }
    return nneeww;
}
