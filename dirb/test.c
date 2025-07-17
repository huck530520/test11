<pre>    int main() {
</pre>
<table summary="events" bgcolor=#e0e0e0>
<tr><td><font color="red">
<a name="error:0"></a>
<!-- merge-key a2dbf45e8d682870f7dd0db9de1bad05 -->
<b>(1) Event var_decl</b>: </font></td>
<td><font color="red">Declaring variable &quot;src&quot; without initializer.</font></td>
</tr>
<tr><td><font color="red">Also see events: </font></td>
<td><font color="red">[<a href="#error:1">uninit_use_in_call</a>]</font></td></tr>
</table>
<pre>        char *src = malloc(1024); // Initialize src with allocated memory
    int *p = malloc(100);
</pre>
<table summary="events" bgcolor=#e0e0e0>
<tr><td><font color="red">
<a name="error:1"></a>
<a name="error"></a>
<!-- merge-key a2dbf45e8d682870f7dd0db9de1bad05 -->
<b>(2) Event uninit_use_in_call</b>: </font></td>
<td><font color="red">Using uninitialized value &quot;src&quot; when calling &quot;memcpy&quot;.</font></td>
</tr>
<tr><td><font color="red">Also see events: </font></td>
<td><font color="red">[<a href="#error:0">var_decl</a>]</font></td></tr>
</table>
<pre>        memcpy(p, src, 1024);
    int *q = 4;
}
</pre>
