#include <stdio.h>

// Step 17 - the final version
// This version splits out of the main loop the functions that decode and
// and print a specific piece of the text.
// The main function now has only the logic.

char *encoded_text =
    "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+"
    ",/#\;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l \q#'+d'K#!/+k#;q#"
    "'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# \){nl]!/n{n"
    "#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' \iwk{KK{nl]!/w"
    "{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c \;;{nl'-{}rw]'/+,}##'*}#n"
    "c,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# \}'+}##(!!/";

char *cypher =
    "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:"
   "\nuwloca-O;m .vpbks,fxntdCeghiry";

void decode_text(char *text) {
    while (*text != '/') {
        char *p = cypher;
        while (*text != *p) p++;
        putchar(p[31]);
        text++;
    }
}

void move_to_segment_and_decode(int segment) {
    int slashes_so_far = 0;
    char *p = encoded_text;
    while (slashes_so_far < segment) {
        if (*p++ == '/') {
            slashes_so_far++;
        }
    }
    decode_text(p);
}

void print_day_preamble(int day) {
    decode_text(encoded_text);
    move_to_segment_and_decode(day);
    move_to_segment_and_decode(13);
}

int f(int p1, int p2) {
    if (p1 == 2) {
        print_day_preamble(p2 - 1);
    }

    if (p1 < 0) {
        move_to_segment_and_decode(-p1);
        return 1;
    }

    if (p1 < p2) {
        f(p1 + 1, p2);
     }

    move_to_segment_and_decode(27 - p1);

    if (p1 == 2) {
        if (p2 < 13) {
            return f(2, p2 + 1);
        }
    }
}

int main(int argc, char *argv[]) {
    // Call with the value that kicks off the code (2)
    f(2, 2);
}
