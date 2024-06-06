.PHONY: clean All

All:
	@echo "----------Building project:[ SimancasVaraManuel - Debug ]----------"
	@cd "SimancasVaraManuel" && "$(MAKE)" -f  "SimancasVaraManuel.mk"
clean:
	@echo "----------Cleaning project:[ SimancasVaraManuel - Debug ]----------"
	@cd "SimancasVaraManuel" && "$(MAKE)" -f  "SimancasVaraManuel.mk" clean
