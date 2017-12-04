ifeq ($(shell uname -s),Linux)
	NO_COLOR="\033[0m"
	OK_COLOR="\033[0;32m"
	ERROR_COLOR="\033[0;31m"
else
	NO_COLOR="\x1b[0m"
	OK_COLOR="\x1b[32;01m"
	ERROR_COLOR="\x1b[31;01m"
endif

TEST_LOG = test.log

ECHO = /bin/echo -e -n

OK_STRING=$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING=$(ERROR_COLOR)[ERRORS]$(NO_COLOR)

VPATH = avm/

TESTS = 01_test.avm				\
		02_test.avm				\
		03_test.avm				\
		04_test.avm				\
		05_test.avm				\
		06_add_int.avm			\
		07_sub_int.avm			\
		08_mul_int.avm			\
		09_div_int.avm			\
		10_div_int_by_zero.avm	\
		11_mod_int.avm			\
		11_mod_int_by_zero.avm	\
		12_pop.avm				\
		13_print.avm			\
		14_print_not_char.avm	\
		15_print_invalid.avm	\
		16_assert.avm			\
		17_error_unknow_instruction.avm \
		18_error_invalid_format.avm	\
		19_float_no_dot.avm		\
		20_double_no_dot.avm	\
		21_comment_after_push.avm	\
		22_int_with_dot.avm		\
		23_double_with_multiple_dots.avm

REAL_TESTS = $(TESTS)

OUT_DIR = out/

OUTS = $(addprefix $(OUT_DIR), $(REAL_TESTS:.avm=.txt))

EXPECTED_DIR = expected/

all: $(OUTS)

$(OUT_DIR)%.txt: %.avm
	@#OUT2=`valgrind --leak-check=full ../avm $< 2>&1 | grep -v 'possibly lost' | grep -E -A5 'lost in loss record|Invalid read of size|SIG.*'`;
	@mkdir -p $(shell dirname $@)
	@../avm $< > $@
	@echo -n "$<: "
	@OUT1=`diff $@ $(EXPECTED_DIR)$(shell basename $@)`; \
	if [ -z "$$OUT1" ]; then \
		$(ECHO) $(OK_STRING); \
	else \
		$(ECHO) $(ERROR_STRING); \
		echo "$<: " >> $(TEST_LOG); \
		echo $$OUT1 >> $(TEST_LOG); \
	fi; \
	OUT2=`valgrind --leak-check=full ../avm $< 2>&1 | grep -v 'possibly lost' | grep -E -A5 'lost in loss record|Invalid read of size|SIG.*'`; \
	if [ -z "$$OUT2" ]; then \
		$(ECHO) $(OK_STRING); \
	else \
		$(ECHO) $(ERROR_STRING); \
		echo "$<: " >> $(TEST_LOG); \
		echo $$OUT2 >> $(TEST_LOG); \
	fi; \
	echo ""; \
	if [ -n "$$OUT1" ]; then \
		echo "$$OUT1"; \
	fi; \
	if [ -n "$$OUT2" ]; then \
		echo "$$OUT2"; \
	fi;


clean:
	@echo cleaning!
	@/bin/rm -rf $(OUT_DIR)
	@/bin/rm -rf $(TEST_LOG)

re: clean all
