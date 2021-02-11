-- Testbench automatically generated online
-- at https://vhdl.lapinoo.net
-- Generation date : 11.2.2021 14:26:08 UTC

library ieee;
use ieee.std_logic_1164.all;
use IEEE.numeric_std.all;

entity tb_PGCD is
end tb_PGCD;

architecture tb of tb_PGCD is

    component PGCD
        port (CLK      : in std_logic;
              RESET    : in std_logic;
              idata_a  : in std_logic_vector (31 downto 0);
              idata_b  : in std_logic_vector (31 downto 0);
              idata_en : in std_logic;
              odata    : out std_logic_vector (31 downto 0);
              odata_en : out std_logic);
    end component;

    signal CLK      : std_logic;
    signal RESET    : std_logic;
    signal idata_a  : std_logic_vector (31 downto 0);
    signal idata_b  : std_logic_vector (31 downto 0);
    signal idata_en : std_logic;
    signal odata    : std_logic_vector (31 downto 0);
    signal odata_en : std_logic;

    constant TbPeriod : time := 1 ns; -- EDIT Put right period here
    signal TbClock : std_logic := '0';
    signal TbSimEnded : std_logic := '0';

begin

    dut : PGCD
    port map (CLK      => CLK,
              RESET    => RESET,
              idata_a  => idata_a,
              idata_b  => idata_b,
              idata_en => idata_en,
              odata    => odata,
              odata_en => odata_en);

    -- Clock generation
    TbClock <= not TbClock after TbPeriod/2 when TbSimEnded /= '1' else '0';

    -- EDIT: Check that CLK is really your main clock signal
    CLK <= TbClock;

    stimuli : process
    begin
        -- EDIT Adapt initialization as needed
        idata_a  <= STD_LOGIC_VECTOR( TO_UNSIGNED( 221, 32) );
        idata_b  <= STD_LOGIC_VECTOR( TO_UNSIGNED( 781, 32) );
        idata_en <= '1';
        while odata_en = '0' loop
            idata_en <= '0';
            wait for 10 ns;
        end loop;

        -- Reset generation
        -- EDIT: Check that RESET is really your reset signal
        RESET <= '1';
        wait for 100 ns;
        RESET <= '0';
        wait for 100 ns;

        -- EDIT Add stimuli here
        wait for 100 * TbPeriod;

        -- Stop the clock and hence terminate the simulation
        TbSimEnded <= '1';
        wait;
    end process;

end tb;

-- Configuration block below is required by some simulators. Usually no need to edit.

configuration cfg_tb_PGCD of tb_PGCD is
    for tb
    end for;
end cfg_tb_PGCD;