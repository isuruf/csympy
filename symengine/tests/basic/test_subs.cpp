#include "catch.hpp"
#include <chrono>

#include <symengine/subs.h>

using SymEngine::Add;
using SymEngine::Basic;
using SymEngine::Boolean;
using SymEngine::boolFalse;
using SymEngine::boolTrue;
using SymEngine::ComplexInf;
using SymEngine::down_cast;
using SymEngine::dummy;
using SymEngine::E;
using SymEngine::erf;
using SymEngine::finiteset;
using SymEngine::function_symbol;
using SymEngine::gamma;
using SymEngine::imageset;
using SymEngine::Integer;
using SymEngine::integer;
using SymEngine::interval;
using SymEngine::is_a;
using SymEngine::kronecker_delta;
using SymEngine::levi_civita;
using SymEngine::logical_and;
using SymEngine::logical_not;
using SymEngine::logical_or;
using SymEngine::logical_xor;
using SymEngine::map_basic_basic;
using SymEngine::msubs;
using SymEngine::Mul;
using SymEngine::multinomial_coefficients;
using SymEngine::Nan;
using SymEngine::one;
using SymEngine::Pow;
using SymEngine::print_stack_on_segfault;
using SymEngine::RCP;
using SymEngine::rcp_dynamic_cast;
using SymEngine::real_double;
using SymEngine::Set;
using SymEngine::set_union;
using SymEngine::sin;
using SymEngine::ssubs;
using SymEngine::subs;
using SymEngine::Symbol;
using SymEngine::symbol;
using SymEngine::umap_basic_num;
using SymEngine::xreplace;
using SymEngine::zero;

TEST_CASE("Mul: subs", "[subs]")
{
    RCP<const Basic> x = symbol("x");

    RCP<const Basic> r1;
    RCP<const Basic> r2;
    map_basic_basic d;
    
    r1 = mul(real_double(2.0), x);
    // xreplace with an empty mapping dict should be a no-op
    r2 = r1->xreplace(d);
    std::cout << "r1: " << *r1 << std::endl;
    std::cout << "r2: " << *r2 << std::endl;
    REQUIRE(eq(*r1, *r2));
}

