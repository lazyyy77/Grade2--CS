<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="A" />
        <signal name="XLXN_2" />
        <signal name="Ci" />
        <signal name="B" />
        <signal name="Ctrl" />
        <signal name="Co" />
        <signal name="S" />
        <port polarity="Input" name="A" />
        <port polarity="Input" name="Ci" />
        <port polarity="Input" name="B" />
        <port polarity="Input" name="Ctrl" />
        <port polarity="Output" name="Co" />
        <port polarity="Output" name="S" />
        <blockdef name="Adder1b">
            <timestamp>2023-11-9T23:35:7</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="xor2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="60" y1="-128" y2="-128" x1="0" />
            <line x2="208" y1="-96" y2="-96" x1="256" />
            <arc ex="44" ey="-144" sx="48" sy="-48" r="56" cx="16" cy="-96" />
            <arc ex="64" ey="-144" sx="64" sy="-48" r="56" cx="32" cy="-96" />
            <line x2="64" y1="-144" y2="-144" x1="128" />
            <line x2="64" y1="-48" y2="-48" x1="128" />
            <arc ex="128" ey="-144" sx="208" sy="-96" r="88" cx="132" cy="-56" />
            <arc ex="208" ey="-96" sx="128" sy="-48" r="88" cx="132" cy="-136" />
        </blockdef>
        <block symbolname="Adder1b" name="XLXI_1">
            <blockpin signalname="XLXN_2" name="B" />
            <blockpin signalname="Ci" name="C" />
            <blockpin signalname="A" name="A" />
            <blockpin signalname="Co" name="Co" />
            <blockpin signalname="S" name="S" />
        </block>
        <block symbolname="xor2" name="XLXI_2">
            <blockpin signalname="Ctrl" name="I0" />
            <blockpin signalname="B" name="I1" />
            <blockpin signalname="XLXN_2" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1696" y="1232" name="XLXI_1" orien="R0">
        </instance>
        <branch name="A">
            <wire x2="1696" y1="1200" y2="1200" x1="1120" />
        </branch>
        <branch name="XLXN_2">
            <wire x2="1600" y1="1008" y2="1008" x1="1456" />
            <wire x2="1600" y1="1008" y2="1072" x1="1600" />
            <wire x2="1696" y1="1072" y2="1072" x1="1600" />
        </branch>
        <branch name="Ci">
            <wire x2="1520" y1="1120" y2="1120" x1="1120" />
            <wire x2="1520" y1="1120" y2="1136" x1="1520" />
            <wire x2="1696" y1="1136" y2="1136" x1="1520" />
        </branch>
        <instance x="1200" y="1104" name="XLXI_2" orien="R0" />
        <branch name="B">
            <wire x2="1200" y1="976" y2="976" x1="1120" />
        </branch>
        <branch name="Ctrl">
            <wire x2="1200" y1="1040" y2="1040" x1="1120" />
        </branch>
        <iomarker fontsize="28" x="1120" y="976" name="B" orien="R180" />
        <iomarker fontsize="28" x="1120" y="1040" name="Ctrl" orien="R180" />
        <iomarker fontsize="28" x="1120" y="1120" name="Ci" orien="R180" />
        <iomarker fontsize="28" x="1120" y="1200" name="A" orien="R180" />
        <branch name="Co">
            <wire x2="2240" y1="1072" y2="1072" x1="2080" />
        </branch>
        <branch name="S">
            <wire x2="2240" y1="1200" y2="1200" x1="2080" />
        </branch>
        <iomarker fontsize="28" x="2240" y="1072" name="Co" orien="R0" />
        <iomarker fontsize="28" x="2240" y="1200" name="S" orien="R0" />
    </sheet>
</drawing>