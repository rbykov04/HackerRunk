OUTPUT_PATH=test.taa


define testing
	cat $(1).test | ./$@
	@echo "[TEST     ] $(1)"
	@if cmp -s $(OUTPUT_PATH) $(1).etalon; \
	then echo '[    GOOD ]'; \
	else \
		 echo "MY result:"; \
		 cat $(OUTPUT_PATH); \
		 echo "\nExpected Output:"; \
		 cat $(1).etalon; \
		 echo '\n[     BAD ]'; \
	fi; 
endef

new_year_chaos: new_year_chaos_make
	@$(call testing,$@-1)


new_year_chaos_make:
	@gcc -g -std=c++11 -Werror -Wall -pedantic new_year_chaos.cpp -lstdc++ -o new_year_chaos

array_DS: array_DS_make
	@$(call testing,$@-1)
	@$(call testing,$@-2)
	@$(call testing,$@-3)


array_DS_make:
	@gcc -g -std=c++11 -Werror -Wall -pedantic array_DS.cpp -lstdc++ -o array_DS

warm_repeated_string: warm_repeated_string_make
	@$(call testing,$@-1)
	@$(call testing,$@-2)


warm_repeated_string_make:
	@gcc -g -std=c++11 -Werror -Wall -pedantic warm_repeated_string.cpp -lstdc++ -o warm_repeated_string

all: say


usage:
	@echo "Hi, i am makefile"
clean:
	rm warm_repeated_string
	rm array_DS
	rm new_year_chaos
