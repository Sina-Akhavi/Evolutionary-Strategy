#include <evolutionary_for_mahak.h>
#include <string.h>

int sc_main(int argc, char* argv[]) {

    mahak evol1("evolutionary_strategy");
    evol1.initialize_population();
    evol1.print_population();

    int member_id = 9;
    double price = evol1.compute_price(member_id);
    printf("%f", price);

    return 0;
}

