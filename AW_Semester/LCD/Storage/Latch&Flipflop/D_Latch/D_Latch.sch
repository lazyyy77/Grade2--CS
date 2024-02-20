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
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="XLXN_10" />
        <signal name="XLXN_8" />
        <signal name="Q" />
        <signal name="Q_" />
        <signal name="XLXN_23" />
        <signal name="XLXN_27" />
        <signal name="C" />
        <signal name="XLXN_14" />
        <signal name="D" />
        <port polarity="Output" name="Q" />
        <port polarity="Output" name="Q_" />
        <port polarity="Input" name="C" />
        <port polarity="Input" name="D" />
        <blockdef name="nand2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="216" y1="-96" y2="-96" x1="256" />
            <circle r="12" cx="204" cy="-96" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
        </blockdef>
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <block symbolname="nand2" name="XLXI_2">
            <blockpin signalname="XLXN_10" name="I0" />
            <blockpin signalname="Q" name="I1" />
            <blockpin signalname="Q_" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_1">
            <blockpin signalname="Q_" name="I0" />
            <blockpin signalname="XLXN_8" name="I1" />
            <blockpin signalname="Q" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_5">
            <blockpin signalname="C" name="I0" />
            <blockpin signalname="D" name="I1" />
            <blockpin signalname="XLXN_8" name="O" />
        </block>
        <block symbolname="nand2" name="XLXI_6">
            <blockpin signalname="XLXN_14" name="I0" />
            <blockpin signalname="C" name="I1" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_7">
            <blockpin signalname="D" name="I" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <iomarker fontsize="28" x="2192" y="816" name="Q_" orien="R0" />
        <iomarker fontsize="28" x="2192" y="480" name="Q" orien="R0" />
        <branch name="XLXN_10">
            <wire x2="1712" y1="848" y2="848" x1="1568" />
        </branch>
        <branch name="XLXN_8">
            <wire x2="1712" y1="448" y2="448" x1="1568" />
        </branch>
        <instance x="1712" y="912" name="XLXI_2" orien="R0" />
        <instance x="1712" y="576" name="XLXI_1" orien="R0" />
        <branch name="Q">
            <wire x2="1552" y1="608" y2="784" x1="1552" />
            <wire x2="1712" y1="784" y2="784" x1="1552" />
            <wire x2="2032" y1="608" y2="608" x1="1552" />
            <wire x2="2032" y1="480" y2="480" x1="1968" />
            <wire x2="2192" y1="480" y2="480" x1="2032" />
            <wire x2="2032" y1="480" y2="608" x1="2032" />
        </branch>
        <branch name="Q_">
            <wire x2="1632" y1="512" y2="688" x1="1632" />
            <wire x2="2112" y1="688" y2="688" x1="1632" />
            <wire x2="2112" y1="688" y2="816" x1="2112" />
            <wire x2="2192" y1="816" y2="816" x1="2112" />
            <wire x2="1712" y1="512" y2="512" x1="1632" />
            <wire x2="2112" y1="816" y2="816" x1="1968" />
        </branch>
        <branch name="C">
            <wire x2="1248" y1="656" y2="656" x1="976" />
            <wire x2="1248" y1="656" y2="816" x1="1248" />
            <wire x2="1312" y1="816" y2="816" x1="1248" />
            <wire x2="1312" y1="480" y2="480" x1="1248" />
            <wire x2="1248" y1="480" y2="656" x1="1248" />
        </branch>
        <branch name="XLXN_14">
            <wire x2="1312" y1="880" y2="880" x1="1296" />
        </branch>
        <branch name="D">
            <wire x2="1056" y1="416" y2="416" x1="976" />
            <wire x2="1312" y1="416" y2="416" x1="1056" />
            <wire x2="1056" y1="416" y2="880" x1="1056" />
            <wire x2="1072" y1="880" y2="880" x1="1056" />
        </branch>
        <instance x="1312" y="544" name="XLXI_5" orien="R0" />
        <instance x="1312" y="944" name="XLXI_6" orien="R0" />
        <instance x="1072" y="912" name="XLXI_7" orien="R0" />
        <iomarker fontsize="28" x="976" y="416" name="D" orien="R180" />
        <iomarker fontsize="28" x="976" y="656" name="C" orien="R180" />
    </sheet>
</drawing>