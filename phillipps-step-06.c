#include <stdio.h>

// Step 6 - simplify decision paths
// Some of the decision paths are redundant. For example, in the code:
//    if (t < 0) {
//        if (t < -72) {
// The second "if" can be moved outside because the "t < 0" is redundant.
//
// In this sequence...
//    if (t > 1) {
//        if (t < 3) {
// ...t can only be == 2, so it will be made explicit

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
    if (t == 2) {
        int tmp1 = f(-86, 0, a + 1);
        int tmp2 = f(-87, 1 - _, tmp1 + a);
        f(-79, -13, a + tmp2);
    }

    if (t > 1) {
        if (t < _) {
            f(t + 1, _, a);
        }
        if (f(-94, -27 + t, a) && t == 2) {
            if (_ < 13) {
                return f(2, _ + 1, "%s %d %d\n");
            }
            return 9;
        }
        return 16;
    }

    if (t < -72) {
        return f(_, t, large_string);
    }

    if (t < -50) {
        if (_ == *a) {
            return putchar(31 [a]);
        }
        return f(-65, _, a + 1);
    }

    if (t < 0) {
        return f((*a == '/') + t, _, a + 1);
    }

    // Because of "if (t > 1)" above, "t > 0" means that t == 1 at this point
    if (t == 1) {
        return f(2, 2, "%s");
    }

    // t == 0
    // (because the code above handled t < 0, t > 1 and t == 1)
    if (*a == '/') {
        return 1;
    }
    int tmp = f(-61, *a, small_string);
    return f(0, tmp, a + 1);
}

int main(int argc, char *argv[]) {
    // The original program ("main(t,_,a)) makes a decision based on "t", which is argc
    // When called with no arguments, argc == 1, so we emulate that by calling
    // the new function once with 1 as the first parameter to get it started
    f(1, 0, 0);
}
