#include "include/libs.h"

int main(int argc, char **argv) {
	char *v[6] = {"qweqr", "zxc", "Hello world"};
	printf("=== Echo Test\n");
	echo(3, v);
	printf("\n");

	/*
	 * Path Parse Test
	 */
	printf("=== Path Parse Test\n");
	char *path = "/hello/my/name/is";
	char *path2 = "/test/path/t/e/s/t";
	t_path *test = ft_path_parse(path);
	t_path *test2 = ft_path_parse(path2);
	parsetest(test);
	parsetest(test2);
	printf("\n");

	/*
	 *
	 */
	return 0;
}
