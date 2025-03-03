int *p = NULL;
if (p != NULL) {
  *p = 0;
}
// patch 1
// patch 3
#pragma coverity compliance block deviate "UNINIT"
int *p2 = NULL;
if (p2 != NULL) {
  *p2 = 4;
}
int p4;
if (p2 != NULL) {
  *p2 = 100;
}
#pragma coverity compliance end_block "UNINIT"

// test comment
// out_of_bound_access(2048); // Commented out to prevent out-of-bounds access
return 0;