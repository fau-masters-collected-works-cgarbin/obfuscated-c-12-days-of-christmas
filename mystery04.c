#include <stdio.h>

// Step 4 - make more readable
// Change ?: to if/else to make it easier to follow
//    A "?" becomes an "if"
//    A ":" becomes an "else"

char *large_string =
    "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+"
    ",/#\;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l \q#'+d'K#!/+k#;q#"
    "'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# \){nl]!/n{n"
    "#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' \iwk{KK{nl]!/w"
    "{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c \;;{nl'-{}rw]'/+,}##'*}#n"
    "c,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# \}'+}##(!!/";
char *small_string =
    "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry";

f(t, _, a) char *a;
{
     if (!0 < t) {
        if (t < 3) {
            f(-79, -13, a + f(-87, 1 - _, f(-86, 0, a + 1) + a));
        } else {
            1;
        }
        if (t < _) {
            f(t + 1, _, a);
        } else {
            3;
        }
        if (f(-94, -27 + t, a) && t == 2) {
            if (_ < 13) {
                return f(2, _ + 1, "%s %d %d\n");
            } else {
                return 9;
            }
        } else {
            return 16;
        }
    }
    else {
        if (t < 0) {
            if (t < -72) {
                return f(_, t, large_string);
            } else {
                if (t < -50) {
                    if (_ == *a) {
                        return putchar(31 [a]);
                    } else {
                        return f(-65, _, a + 1);
                    }
                } else {
                    return f((*a == '/') + t, _, a + 1);
                }
            }
        } else {
            if (0 < t) {
                return f(2, 2, "%s");
            } else {
                return *a == '/' || f(0, f(-61, *a, small_string), a + 1);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    // The original program ("main(t,_,a)) makes a decision based on "t", which
    // is argc When called with no arguments, argc == 1, so we emulate that by
    // calling the new function once with 1 as the first parameter to get it
    // started
    f(1, 0, 0);
}
