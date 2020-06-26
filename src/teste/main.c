int __main2(int argc, const char *argv[])
{
	int index;
	int nodenum;

	UNUSED(argc);
	UNUSED(argv);

	index   = -1;
	nodenum = knode_get_num();

	uprintf("nodenum -> . %d" , nodenum);

	if (nodenum == PROCESSOR_NODENUM_MASTER)
		uprintf(HLINE);

	return (0);
}