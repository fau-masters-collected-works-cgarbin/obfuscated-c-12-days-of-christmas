
#include <stdio.h>

// Step 1
// This is the original program, just modified to work with a modern C compiler

f(t, _, a) char *a;
{
    return !0 < t ? t < 3 ? f(-79, -13, a + f(-87, 1 - _, f(-86, 0, a + 1) + a)) : 1, t < _ ? f(t + 1, _, a) : 3, f(-94, -27 + t, a) && t == 2 ? _ < 13 ? f(2, _ + 1, "%s %d %d\n") : 9 : 16 : t < 0 ? t < -72 ? f(_, t, "@n'+,#'/*{}w+/w#cdnr/+,{}r/*de}+,/*{*+,/w{%+,/w#q#n+,/#{l+,/n{n+,/+#n+,/#\;#q#n+,/+k#;*+,/'r :'d*'3,}{w+K w'K:'+}e#';dq#'l \q#'+d'K#!/+k#;q#'r}eKK#}w'r}eKK{nl]'/#;#q#n'){)#}w'){){nl]'/+#n';d}rw' i;# \){nl]!/n{n#'; r{#w'r nc{nl]'/#{l,+'K {rw' iK{;[{nl]'/w#q#n'wk nw' \iwk{KK{nl]!/w{%'l##w#' i; :{nl]'/*{q#'ld;r'}{nlwb!/*de}'c \;;{nl'-{}rw]'/+,}##'*}#nc,',#nw]'/+kd'+e}+;#'rdq#w! nr'/ ') }+}{rl#'{n' ')# \}'+}##(!!/") : t < -50 ? _ == *a ? putchar(31 [a]) : f(-65, _, a + 1) : f((*a == '/') + t, _, a + 1) : 0 < t ? f(2, 2, "%s") : *a == '/' || f(0, f(-61, *a, "!ek;dc i@bK'(q)-[w]*%n+r3#l,{}:\nuwloca-O;m .vpbks,fxntdCeghiry"), a + 1);
}

int main(int argc, char *argv[])
{
    // The original program ("main(t,_,a)) makes a decision based on "t", which is argc
    // When called with no arguments, argc == 1, so we emulate that by calling
    // the new function once with 1 as the first parameter to get it started
    f(1, 0, 0);
}
