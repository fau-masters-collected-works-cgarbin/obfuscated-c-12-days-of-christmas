#include <stdio.h>

// Step 15 - split out code that prints a piece of text
// To help see the logic of the main function, the code that prints one piece
// of text is moved to its own function
// It is also clear now that the small string is acting as a cipher: a
// character from the large string is translated into a character 31
// positions ahead in the small string
// The call to decode the text when p1 == 2 is also replaced with a direct
// call to the decode function - this makes it clearer that p1 == 2 is the
// initialization code for the program
// Finally, if we move the "p1 < 0" code up, we can remove the "p1 > 1" test
// At this point, with the code pretty much reworked, it was also changed
// to modern C, e.g. declare function types, etc.

char *large_string =
    "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+"
    ",/#\;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l \q#'+d'K#!/+k#;q#"
    "'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# \){nl]!/n{n"
    "#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' \iwk{KK{nl]!/w"
    "{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c \;;{nl'-{}rw]'/+,}##'*}#n"
    "c,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# \}'+}##(!!/";
char *small_string =
    "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry";

#define PRINT_ONE_PIECE (0)

void decode_text(char* text) {
    while (*text != '/') {
        char *p = small_string;
        while (*text != *p) p++;
        putchar(p[31]);
        text++;
    }
}

int f(int p1, int p2, char* p3)
{
    if (p1 == PRINT_ONE_PIECE) {
        decode_text(p3);
        return 1;
    }

    if (p1 == 2) {
        decode_text(large_string);
        f(1 - p2, 0, large_string);
        f(-13, 0, large_string);
    }

    if (p1 < 0) {
        return f((*p3 == '/') + p1, p2, p3 + 1);
    }

    if (p1 < p2) {
        f(p1 + 1, p2, p3);
    }

    if (f(-27 + p1, 0, large_string) && p1 == 2) {
        if (p2 < 13) {
            return f(2, p2 + 1, 0);
        }
    }
}

int main(int argc, char *argv[]) {
    // Call with the value that kicks off the code (2)
    f(2, 2, 0);
}
