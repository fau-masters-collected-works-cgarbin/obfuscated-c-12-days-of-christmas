#include <stdio.h>

// Step 11 - eliminate SWAP_VARIABLES
// After simplifying SWAP_VARIABLES, it becomes clear that it is just a
// misdirection - it can be replaced by direct calls to the function, with
// the arguments already swapped
// Also, when the function is called with p1 == 2, the third parameter is not
// used - remove some bogus strings used in those cases

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
#define ADVANCE_OR_PRINT (-51)

f(p1, p2, p3) char *p3;
{
    // Called recursively until a "/" is found in p3
    if (p1 == GO_TO_SLASH) {
        if (*p3 == '/') {
            return 1;
        }
        int tmp = f(ADVANCE_OR_PRINT, *p3, small_string);
        return f(GO_TO_SLASH, tmp, p3 + 1);
    }

    if (p1 == 1) {
        return f(2, 2, 0);
    }

    if (p1 == 2) {
        f(GO_TO_SLASH, 0, large_string);
        f(1 - p2, 0, large_string);
        f(-13, 0, large_string);
    }

    // Find p2 in p3 and print it
    if (p1 < (ADVANCE_OR_PRINT + 1)) {
        if (p2 == *p3) {
            return putchar(p3[31]);
        }
        return f(ADVANCE_OR_PRINT, p2, p3 + 1);
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
    // The original program ("main(t,_,a)) makes a decision based on "t", which
    // is argc When called with no arguments, argc == 1, so we emulate that by
    // calling the new function once with 1 as the first parameter to get it
    // started
    f(1, 0, 0);
}
