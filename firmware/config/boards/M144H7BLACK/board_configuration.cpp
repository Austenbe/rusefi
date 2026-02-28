#include "pch.h"
#include "defaults.h"
#include "M144_meta.h"
#include "board_overrides.h"

Gpio getCommsLedPin() {
	return Gpio::Unassigned;
}

Gpio getRunningLedPin() {
	return Gpio::Unassigned;
}

Gpio getWarningLedPin() {
	return Gpio::Unassigned;
}


// board-specific configuration setup
void m144h7black_boardDefaultConfiguration() {
   	engineConfiguration->analogInputDividerCoefficient = 1.47f;
	engineConfiguration->adcVcc = 3.3f;
	engineConfiguration->isSdCardEnabled = true;
    engineConfiguration->alwaysWriteSdCard = true;
// #ifdef TS_SECONDARY_UxART_PORT
// 	engineConfiguration->binarySerialTxPin = Gpio::F7;
// 	engineConfiguration->binarySerialRxPin = Gpio::F6;
// #endif // TS_SECONDARY_UxART_PORT		
}

bool isBoardAllowingLackOfPps() {
	return engineConfiguration->allowIdenticalPps;
}

void m144h7black_boardConfigOverrides() {
	engineConfiguration->is_enabled_spi_3 = true;
	engineConfiguration->sdCardCsPin = Gpio::D2;
	engineConfiguration->sdCardSpiDevice = SPI_DEVICE_3;
	engineConfiguration->spi3mosiPin = Gpio::C12;
	engineConfiguration->spi3misoPin = Gpio::C11;
	engineConfiguration->spi3sckPin  = Gpio::C10;
}

void setup_custom_board_overrides() {
	custom_board_DefaultConfiguration = m144h7black_boardDefaultConfiguration;
	custom_board_ConfigOverrides = m144h7black_boardConfigOverrides;
}

#include "connectors/generated_outputs.h"

int getBoardMetaOutputsCount() {
	return efi::size(GENERATED_OUTPUTS);
}

int getBoardMetaLowSideOutputsCount() {
	return getBoardMetaOutputsCount() - 16;
}

Gpio* getBoardMetaOutputs() {
	return GENERATED_OUTPUTS;
}


int getBoardMetaDcOutputsCount() {
	return 2;
}
