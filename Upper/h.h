// The exact definition of __FILE__ is influenced
// by the include path used to find this file.
// __FILE__ in .h files is therefore a subtle
// and common one definition rule (ODR) violation farm.
inline const char* file() { return __FILE__;}
