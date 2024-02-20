<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_2" />
        <signal name="XLXN_4" />
        <signal name="XLXN_11" />
        <signal name="XLXN_67" />
        <signal name="XLXN_76" />
        <signal name="XLXN_80" />
        <signal name="XLXN_87" />
        <signal name="XLXN_91" />
        <signal name="XLXN_99" />
        <signal name="XLXN_107" />
        <signal name="XLXN_115" />
        <signal name="XLXN_126" />
        <signal name="XLXN_133" />
        <signal name="XLXN_140" />
        <signal name="XLXN_147" />
        <signal name="XLXN_154" />
        <signal name="XLXN_157" />
        <signal name="XLXN_158" />
        <signal name="S" />
        <signal name="R" />
        <signal name="XLXN_165" />
        <signal name="XLXN_168" />
        <signal name="XLXN_170" />
        <signal name="C" />
        <signal name="Q_" />
        <signal name="Q" />
        <port polarity="Input" name="S" />
        <port polarity="Input" name="R" />
        <port polarity="Input" name="C" />
        <port polarity="Output" name="Q_" />
        <port polarity="Output" name="Q" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="CSR_Latch">
            <timestamp>2023-11-13T8:36:4</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="CSR_Latch" name="XLXI_70">
            <blockpin signalname="C" name="C" />
            <blockpin signalname="S" name="S" />
            <blockpin signalname="R" name="R" />
            <blockpin signalname="XLXN_170" name="Q_" />
            <blockpin signalname="XLXN_168" name="Q" />
        </block>
        <block symbolname="CSR_Latch" name="XLXI_71">
            <blockpin signalname="XLXN_165" name="C" />
            <blockpin signalname="XLXN_168" name="S" />
            <blockpin signalname="XLXN_170" name="R" />
            <blockpin signalname="Q_" name="Q_" />
            <blockpin signalname="Q" name="Q" />
        </block>
        <block symbolname="inv" name="XLXI_73">
            <blockpin signalname="C" name="I" />
            <blockpin signalname="XLXN_165" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1376" y="1552" name="XLXI_70" orien="R0">
        </instance>
        <instance x="2016" y="1552" name="XLXI_71" orien="R0">
        </instance>
        <branch name="S">
            <wire x2="1376" y1="1456" y2="1456" x1="1120" />
        </branch>
        <branch name="R">
            <wire x2="1376" y1="1520" y2="1520" x1="1120" />
        </branch>
        <branch name="XLXN_165">
            <wire x2="1920" y1="1680" y2="1680" x1="1696" />
            <wire x2="2016" y1="1392" y2="1392" x1="1920" />
            <wire x2="1920" y1="1392" y2="1680" x1="1920" />
        </branch>
        <branch name="XLXN_168">
            <wire x2="1808" y1="1520" y2="1520" x1="1760" />
            <wire x2="1808" y1="1456" y2="1520" x1="1808" />
            <wire x2="2016" y1="1456" y2="1456" x1="1808" />
        </branch>
        <branch name="XLXN_170">
            <wire x2="1872" y1="1392" y2="1392" x1="1760" />
            <wire x2="1872" y1="1392" y2="1520" x1="1872" />
            <wire x2="2016" y1="1520" y2="1520" x1="1872" />
        </branch>
        <branch name="C">
            <wire x2="1280" y1="1392" y2="1392" x1="1120" />
            <wire x2="1376" y1="1392" y2="1392" x1="1280" />
            <wire x2="1280" y1="1392" y2="1680" x1="1280" />
            <wire x2="1472" y1="1680" y2="1680" x1="1280" />
        </branch>
        <instance x="1472" y="1712" name="XLXI_73" orien="R0" />
        <iomarker fontsize="28" x="1120" y="1392" name="C" orien="R180" />
        <iomarker fontsize="28" x="1120" y="1456" name="S" orien="R180" />
        <iomarker fontsize="28" x="1120" y="1520" name="R" orien="R180" />
        <branch name="Q_">
            <wire x2="2432" y1="1392" y2="1392" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1392" name="Q_" orien="R0" />
        <branch name="Q">
            <wire x2="2432" y1="1520" y2="1520" x1="2400" />
        </branch>
        <iomarker fontsize="28" x="2432" y="1520" name="Q" orien="R0" />
    </sheet>
</drawing>