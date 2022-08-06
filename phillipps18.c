#include <stdio.h>

// Step 18 - the final version
// This version replaces the recursive calls with loops

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

int main(int argc, char *argv[]) {
    for (int day = 1; day < 13; day++) {
        print_day_preamble(day);
        for (int i = day + 1; i >= 2; i--) {
            move_to_segment_and_decode(27 - i);
        }
    }
}
