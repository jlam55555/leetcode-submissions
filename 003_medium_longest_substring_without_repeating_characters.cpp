int lengthOfLongestSubstring(char * s){
    short last_char_pos_map[256], i;
    int last_start = 0,
        longest_length = 0,
        len = strlen(s);
    char c;
    
    for(i = 0; i < 256; i++)
        last_char_pos_map[i] = -1;

    for(i = 0; i < len; i++) {
        c = s[i];
        if(last_char_pos_map[c] >= last_start) {
            if(i - last_start > longest_length)
                longest_length = i - last_start;
            last_start = last_char_pos_map[c] + 1;
        }
        last_char_pos_map[c] = i;
    }
    if(i - last_start > longest_length)
        longest_length = i - last_start;
    return longest_length;
}
