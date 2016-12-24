/* Your task  is to implement the function strstr. The function takes two strings as arguments(s,x) and  locates the occurrence of the string x in the string s. The function returns and integer denoting  the first occurrence of the string x . */

int strstr(string s, string x)
{
    //Your code here
    if (s.size() < x.size()) return -1;

    int pos = -1;
    int j = 0;

    for (int i = 0; i < s.size() - x.size(); i++){
        bool found = false;
        j = 0;
        int aux = i;
        while (x[j] == s[aux]){
            pos = i;
            j++;
            aux++;
        //    cout <<  "comparing x["<< j << "] = " << x[j] << " with s[" << aux << "] = " << s[aux] << endl;
            if (x[j] == '\0')
                found = true;
        }
        if (found)
            break;
        else
            pos = -1;
    }
    return pos;
}
