#include <stdio.h>

// Step 13 - replace recursion to print characters with a loop
// The recursion in the ADVANCE_OR_PRINT branch is used only to advance the
// pointer to the character we want to print - it can be replaced with a simple
// loop to make the code easier to follow
// We can also rename ADVANCE_OR_PRINT to simply PRINT

char *large_string =
    "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+"
    ",/#\;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l \q#'+d'K#!/+k#;q#"
    "'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# \){nl]!/n{n"
    "#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' \iwk{KK{nl]!/w"
    "{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c \;;{nl'-{}rw]'/+,}##'*}#n"
    "c,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# \}'+}##(!!/";
char *small_string =
    "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry";

#define GO_TO_SLASH (0)
#define PRINT (-51)

f(p1, p2, p3) char *p3;
{
    // Called recursively until a "/" is found in p3
    if (p1 == GO_TO_SLASH) {
        if (*p3 == '/') {
            return 1;
        }
        int tmp = f(PRINT, *p3, small_string);
        return f(GO_TO_SLASH, tmp, p3 + 1);
    }

    if (p1 == 2) {
        f(GO_TO_SLASH, 0, large_string);
        f(1 - p2, 0, large_string);
        f(-13, 0, large_string);
    }

    // Find p2 in p3 and print it
    if (p1 < (PRINT + 1)) {
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
