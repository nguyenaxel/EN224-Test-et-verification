----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 09.02.2021 15:58:15
-- Design Name: 
-- Module Name: pgcd - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

ENTITY PGCD IS
PORT ( 
	CLK      : in  STD_LOGIC;
	RESET    : in  STD_LOGIC;

	idata_a  : in  STD_LOGIC_VECTOR (31 downto 0);
	idata_b  : in  STD_LOGIC_VECTOR (31 downto 0);
	idata_en : in  STD_LOGIC;

	odata    : out STD_LOGIC_VECTOR (31 downto 0);
	odata_en : out STD_LOGIC
);
END PGCD;

architecture Behavioral of pgcd is

    type state is (idle, st1);
    signal current_state, next_state : state;
    signal end_pgcd_calcul : std_logic := '0';
begin

    evolution : process(current_state, idata_en)
    begin
        case current_state is
            when idle =>
                if idata_en = '1' then
                    next_state <= st1;
                else
                    next_state <= idle;
                end if;
            when st1 =>
                if end_pgcd_calcul = '1' then
                    next_state <= idle;
                else 
                    next_state <= st1;
                end if;
            when others =>
                    next_state <= idle;
        end case;
    end process;

    memorisation : process
    begin
        if(reset = '0') then
            current_state <= idle;
        elsif rising_dege(clk) then
            current_state <= next_state;
        end if;
    end process;
    
    mise_a_jour_sorties : process
    begin
        if(current_state = st1) then
            while(idata_a /= idata_b) loop
                if(idata_a > idata_b) then
                    idata_a <= idata_a - idata_b;
                end if;
            end loop;
        end if;
    end process;

end Behavioral;
