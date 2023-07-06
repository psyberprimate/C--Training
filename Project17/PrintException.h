#ifndef __Print_EXCEPTION__
#define __Print_EXCEPTION__



class PrintException: public std::exception {
    public:
        PrintException() noexcept = default;
        ~PrintException() = default;
        virtual const char* what() const noexcept {
            return "File cannot be opened";
        }
};


#endif // __Print_EXCEPTION__
