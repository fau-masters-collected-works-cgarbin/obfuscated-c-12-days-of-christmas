#include <stdio.h>

// Step 14 - improve GO_TO_SLASH
// After improving the (new) PRINT, it is clearer now that GO_TO_SLASH is not
// only going to a slash, but printing each character along the way
// To make it easier to follow, the recursion is replaced with a loop
// The constant name is also changed to better reflect what it does

char *large_string =
    "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+,/"
    "#\;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l "
    "\q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' "
    "i;# \){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' "
    "\iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c "
    "\;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' "
    "')# \}'+}##(!!/";
char *small_string =
    "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry";

#define PRINT_ONE_PIECE (0)
#define PRINT_ONE_LETTER (-51)

f(p1, p2, p3) char *p3;
{
    // Called recursively until a "/" is found in p3
    if (p1 == PRINT_ONE_PIECE) {
        while (*p3 != '/')
            f(PRINT_ONE_LETTER, *p3++, small_string);
        return 1;
    }

    if (p1 == 2) {
        f(PRINT_ONE_PIECE, 0, large_string);
        f(1 - p2, 0, large_string);
        f(-13, 0, large_string);
    }

    // Find p2 in p3 and print it
    if (p1 < (PRINT_ONE_LETTER + 1)) {
        while (p2 != *p3) p3++;
        return putchar(p3[31]);
    }

    if (p1 > 1) {
        if (p1 < p2) {
            f(p1 + 1, p2, p3);
        }
        if (f(-27 + p1, 0, large_string) && p1 == 2) {
            if (p2 < 13) {
                return f(2, p2 + 1, 0);
            }
            return 9;
        }
        return 16;
    }

    if (p1 < 0) {
        return f((*p3 == '/') + p1, p2, p3 + 1);
    }
}

int main(int argc, char *argv[]) {
    // Call with the value that kicks off the code (2)
    f(2, 2, 0);
}
