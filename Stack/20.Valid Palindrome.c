bool isValid(char* s) {
    int l;
    char *stack, c;
    int sp = 0;
    
    if (!s || !*s) return true;
    
    l = strlen(s);
    stack = malloc(l * sizeof(char));
    //assert(stack);
    while (c = *s ++) {
        switch (c) {
            case '(':
            case '{':
            case '[':
                stack[sp ++] = c;
                break;
            case ')':
                if (sp == 0 || stack[-- sp] != '(') { free(stack); return false; }
                break;
            case '}':
                if (sp == 0 || stack[-- sp] != '{') { free(stack); return false; }
                break;
            case ']':
                if (sp == 0 || stack[-- sp] != '[') { free(stack); return false; }
                break;
            default:
                break;
        }
    }
    
    free(stack);
    return sp == 0 ? true : false;
}
