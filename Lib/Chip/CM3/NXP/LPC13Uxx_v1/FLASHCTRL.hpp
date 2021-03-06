#pragma once 
#include <Register/Utility.hpp>
namespace Kvasir {
//Flash programming firmware  
    namespace FlashctrlEemsstart{    ///<EEPROM BIST start address register
        using Addr = Register::Address<0x4003c09c,0x00000000,0x00000000,unsigned>;
        ///BIST start address: Bit 0 is fixed zero since only even addresses are allowed.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,0),Register::ReadWriteAccess,unsigned> starta{}; 
        ///Reserved
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,14),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace FlashctrlEemsstop{    ///<EEPROM BIST stop address register
        using Addr = Register::Address<0x4003c0a0,0x00000000,0x00000000,unsigned>;
        ///BIST stop address: Bit 0 is fixed zero since only even addresses are allowed.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(13,0),Register::ReadWriteAccess,unsigned> stopa{}; 
        ///Reserved
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(29,14),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///BIST device select bit 0: the BIST signature is generated over the total memory space. Singe pages are interleaved over the EEPROM devices when multiple devices are used, the signature is generated over memory of multiple devices. 1: the BIST signature is generated only over a memory range located on a single EEPROM device. Therefore the internal address generation is done such that the  address' CS bits are kept stable to select only the same device. The address' MSB and LSB bits are used to step through the memory range specified by the start and stop address fields. Note: if this bit is set the start and stop address fields must be programmed such that they both address the same EEPROM device. Therefore the address' CS bits in both the start and stop address must be the same.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(30,30),Register::ReadWriteAccess,unsigned> devsel{}; 
        ///BIST start bit Setting this bit will start the BIST. This bit is self-clearing.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,31),Register::ReadWriteAccess,unsigned> strtbist{}; 
    }
    namespace FlashctrlEemssig{    ///<EEPROM 24-bit BIST signature register
        using Addr = Register::Address<0x4003c0a4,0x00000000,0x00000000,unsigned>;
        ///BIST 16-bit signature calculated from only the data bytes
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(15,0),Register::ReadWriteAccess,unsigned> dataSig{}; 
        ///BIST 16-bit signature calculated from only the parity bits of the data bytes
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,16),Register::ReadWriteAccess,unsigned> paritySig{}; 
    }
    namespace FlashctrlFlashcfg{    ///<Flash memory access time configuration register
        using Addr = Register::Address<0x4003c010,0x00000000,0x00000000,unsigned>;
        ///Flash memory access time. FLASHTIM +1 is equal to the number of system clocks used for flash access.
        enum class FlashtimVal {
            v1SystemClockFlash=0x00000000,     ///<1 system clock flash access time (for system clock frequencies of up to 20 MHz).
            v2SystemClocksFlas=0x00000001,     ///<2 system clocks flash access time (for system clock frequencies of up to 40 MHz).
            v3SystemClocksFlas=0x00000002,     ///<3 system clocks flash access time (for system clock frequencies of up to 50 MHz).
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,FlashtimVal> flashtim{}; 
        namespace FlashtimValC{
            constexpr Register::FieldValue<decltype(flashtim)::Type,FlashtimVal::v1SystemClockFlash> v1SystemClockFlash{};
            constexpr Register::FieldValue<decltype(flashtim)::Type,FlashtimVal::v2SystemClocksFlas> v2SystemClocksFlas{};
            constexpr Register::FieldValue<decltype(flashtim)::Type,FlashtimVal::v3SystemClocksFlas> v3SystemClocksFlas{};
        }
        ///Reserved. User software must not change the value of these bits. Bits 31:2 must be written back exactly as read.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,2),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace FlashctrlFmsstart{    ///<Signature start address register
        using Addr = Register::Address<0x4003c020,0x00000000,0x00000000,unsigned>;
        ///Signature generation start address (corresponds to AHB byte address bits[20:4]).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,0),Register::ReadWriteAccess,unsigned> start{}; 
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,17),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace FlashctrlFmsstop{    ///<Signature stop-address register
        using Addr = Register::Address<0x4003c024,0x00000000,0x00000000,unsigned>;
        ///BIST stop address divided by 16 (corresponds to AHB byte address [20:4]).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(16,0),Register::ReadWriteAccess,unsigned> stop{}; 
        ///Start control bit for signature generation.
        enum class SigstartVal {
            signatureGeneration=0x00000000,     ///<Signature generation is stopped
            initiateSignatureG=0x00000001,     ///<Initiate signature generation
        };
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(17,17),Register::ReadWriteAccess,SigstartVal> sigStart{}; 
        namespace SigstartValC{
            constexpr Register::FieldValue<decltype(sigStart)::Type,SigstartVal::signatureGeneration> signatureGeneration{};
            constexpr Register::FieldValue<decltype(sigStart)::Type,SigstartVal::initiateSignatureG> initiateSignatureG{};
        }
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,18),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace FlashctrlFmsw0{    ///<Word 0 [31:0]
        using Addr = Register::Address<0x4003c02c,0x00000000,0x00000000,unsigned>;
        ///Word 0 of 128-bit signature (bits 31 to 0).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> sw0310{}; 
    }
    namespace FlashctrlFmsw1{    ///<Word 1 [63:32]
        using Addr = Register::Address<0x4003c030,0x00000000,0x00000000,unsigned>;
        ///Word 1 of 128-bit signature (bits 63 to 32).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> sw16332{}; 
    }
    namespace FlashctrlFmsw2{    ///<Word 2 [95:64]
        using Addr = Register::Address<0x4003c034,0x00000000,0x00000000,unsigned>;
        ///Word 2 of 128-bit signature (bits 95 to 64).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> sw29564{}; 
    }
    namespace FlashctrlFmsw3{    ///<Word 3 [127:96]
        using Addr = Register::Address<0x4003c038,0x00000000,0x00000000,unsigned>;
        ///Word 3 of 128-bit signature (bits 127 to 96).
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,0),Register::ReadWriteAccess,unsigned> sw312796{}; 
    }
    namespace FlashctrlFmstat{    ///<Signature generation status register
        using Addr = Register::Address<0x4003cfe0,0x00000000,0x00000000,unsigned>;
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///When 1, a previously started signature generation has completed. See FMSTATCLR register description for clearing this flag.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> sigDone{}; 
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,3),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
    namespace FlashctrlFmstatclr{    ///<Signature generation status clear register
        using Addr = Register::Address<0x4003cfe8,0x00000000,0x00000000,unsigned>;
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(1,0),Register::ReadWriteAccess,unsigned> reserved{}; 
        ///Writing a 1 to this bits clears the signature generation completion flag (SIG_DONE) in the FMSTAT register.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(2,2),Register::ReadWriteAccess,unsigned> sigDoneClr{}; 
        ///Reserved, user software should not write ones to reserved bits. The value read from a reserved bit is not defined.
        constexpr Register::FieldLocation<Addr,Register::maskFromRange(31,3),Register::ReadWriteAccess,unsigned> reserved{}; 
    }
}
