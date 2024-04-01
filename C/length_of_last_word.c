int lengthOfLastWord(char* s) {
    short last = 0, len = 0, i = 0;
    while(s[i]) {
        if(s[i] == ' ') {
            if(len) last = len;
            len = -1;
        }

        i++; len++;
    }

    return !len ? last : len;
}