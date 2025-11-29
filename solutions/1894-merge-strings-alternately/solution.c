char* mergeAlternately(char* word1, char* word2){
    const int l1 = strlen(word1);
    const int l2 = strlen(word2);
    const int l = l1 + l2 + 1;
    char* res = (char*)malloc(l * sizeof(char));

    int p1 = 0;
    int p2 = 0;
    int i = 0;
    bool w = true;

    while (p1 < l1 && p2 < l2)
    {
        if (w) res[i++] = word1[p1++];
        else res[i++] = word2[p2++];
        w = !w;
    }
    while (p1 < l1) res[i++] = word1[p1++];
    while (p2 < l2) res[i++] = word2[p2++];
    res[i] = '\0';

    return res;
}
