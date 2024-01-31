#include <string.h>
#include <evolutionary_for_mahak.h>

int sc_main(int argc, char* argv[]) {

    // test check_and_repair_max_weight
    mahak evol1("evolutionary_strategy");
    evol1.initialize_population();
    evol1.print_population();

    evol1.check_and_repair_max_weight(0);
    printf("-----------------------------\n");
    evol1.print_population();

    return 0;
}