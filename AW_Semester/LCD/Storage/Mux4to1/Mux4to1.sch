<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="s(1:0)" />
        <signal name="s(0)" />
        <signal name="s(1)" />
        <signal name="XLXN_6" />
        <signal name="XLXN_7" />
        <signal name="XLXN_9" />
        <signal name="XLXN_10" />
        <signal name="XLXN_11" />
        <signal name="XLXN_12" />
        <signal name="XLXN_13" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="XLXN_17" />
        <signal name="I0" />
        <signal name="I1" />
        <signal name="I3" />
        <signal name="I2" />
        <signal name="o" />
        <port polarity="Input" name="s(1:0)" />
        <port polarity="Input" name="I0" />
        <port polarity="Input" name="I1" />
        <port polarity="Input" name="I3" />
        <port polarity="Input" name="I2" />
        <port polarity="Output" name="o" />
        <blockdef name="inv">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-32" y2="-32" x1="0" />
            <line x2="160" y1="-32" y2="-32" x1="224" />
            <line x2="128" y1="-64" y2="-32" x1="64" />
            <line x2="64" y1="-32" y2="0" x1="128" />
            <line x2="64" y1="0" y2="-64" x1="64" />
            <circle r="16" cx="144" cy="-32" />
        </blockdef>
        <blockdef name="and2">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="192" y1="-96" y2="-96" x1="256" />
            <arc ex="144" ey="-144" sx="144" sy="-48" r="48" cx="144" cy="-96" />
            <line x2="64" y1="-48" y2="-48" x1="144" />
            <line x2="144" y1="-144" y2="-144" x1="64" />
            <line x2="64" y1="-48" y2="-144" x1="64" />
        </blockdef>
        <blockdef name="or4">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="48" y1="-64" y2="-64" x1="0" />
            <line x2="64" y1="-128" y2="-128" x1="0" />
            <line x2="64" y1="-192" y2="-192" x1="0" />
            <line x2="48" y1="-256" y2="-256" x1="0" />
            <line x2="192" y1="-160" y2="-160" x1="256" />
            <arc ex="112" ey="-208" sx="192" sy="-160" r="88" cx="116" cy="-120" />
            <line x2="48" y1="-208" y2="-208" x1="112" />
            <line x2="48" y1="-112" y2="-112" x1="112" />
            <line x2="48" y1="-256" y2="-208" x1="48" />
            <line x2="48" y1="-64" y2="-112" x1="48" />
            <arc ex="48" ey="-208" sx="48" sy="-112" r="56" cx="16" cy="-160" />
            <arc ex="192" ey="-160" sx="112" sy="-112" r="88" cx="116" cy="-200" />
        </blockdef>
        <block symbolname="inv" name="XLXI_1">
            <blockpin signalname="s(1)" name="I" />
            <blockpin signalname="XLXN_6" name="O" />
        </block>
        <block symbolname="inv" name="XLXI_2">
            <blockpin signalname="s(0)" name="I" />
            <blockpin signalname="XLXN_7" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_3">
            <blockpin signalname="XLXN_7" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="XLXN_10" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_4">
            <blockpin signalname="s(0)" name="I0" />
            <blockpin signalname="XLXN_6" name="I1" />
            <blockpin signalname="XLXN_11" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_5">
            <blockpin signalname="s(1)" name="I0" />
            <blockpin signalname="XLXN_7" name="I1" />
            <blockpin signalname="XLXN_12" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_6">
            <blockpin signalname="s(1)" name="I0" />
            <blockpin signalname="s(0)" name="I1" />
            <blockpin signalname="XLXN_13" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_7">
            <blockpin signalname="I0" name="I0" />
            <blockpin signalname="XLXN_10" name="I1" />
            <blockpin signalname="XLXN_14" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_8">
            <blockpin signalname="I1" name="I0" />
            <blockpin signalname="XLXN_11" name="I1" />
            <blockpin signalname="XLXN_15" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_9">
            <blockpin signalname="I2" name="I0" />
            <blockpin signalname="XLXN_12" name="I1" />
            <blockpin signalname="XLXN_16" name="O" />
        </block>
        <block symbolname="and2" name="XLXI_10">
            <blockpin signalname="I3" name="I0" />
            <blockpin signalname="XLXN_13" name="I1" />
            <blockpin signalname="XLXN_17" name="O" />
        </block>
        <block symbolname="or4" name="XLXI_11">
            <blockpin signalname="XLXN_17" name="I0" />
            <blockpin signalname="XLXN_16" name="I1" />
            <blockpin signalname="XLXN_15" name="I2" />
            <blockpin signalname="XLXN_14" name="I3" />
            <blockpin signalname="o" name="O" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <branch name="s(1:0)">
            <wire x2="1040" y1="800" y2="800" x1="880" />
            <wire x2="1040" y1="800" y2="880" x1="1040" />
            <wire x2="1040" y1="720" y2="800" x1="1040" />
        </branch>
        <iomarker fontsize="28" x="880" y="800" name="s(1:0)" orien="R180" />
        <bustap x2="1136" y1="880" y2="880" x1="1040" />
        <branch name="s(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1160" y="880" type="branch" />
            <wire x2="1160" y1="880" y2="880" x1="1136" />
            <wire x2="1184" y1="880" y2="880" x1="1160" />
            <wire x2="1280" y1="880" y2="880" x1="1184" />
            <wire x2="1440" y1="880" y2="880" x1="1280" />
            <wire x2="1280" y1="880" y2="944" x1="1280" />
            <wire x2="1280" y1="944" y2="1200" x1="1280" />
            <wire x2="2000" y1="1200" y2="1200" x1="1280" />
            <wire x2="2000" y1="944" y2="944" x1="1280" />
        </branch>
        <bustap x2="1136" y1="720" y2="720" x1="1040" />
        <branch name="s(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1152" y="720" type="branch" />
            <wire x2="1152" y1="720" y2="720" x1="1136" />
            <wire x2="1168" y1="720" y2="720" x1="1152" />
            <wire x2="1360" y1="720" y2="720" x1="1168" />
            <wire x2="1440" y1="720" y2="720" x1="1360" />
            <wire x2="1360" y1="720" y2="1104" x1="1360" />
            <wire x2="1360" y1="1104" y2="1120" x1="1360" />
            <wire x2="1360" y1="1120" y2="1264" x1="1360" />
            <wire x2="2000" y1="1264" y2="1264" x1="1360" />
            <wire x2="2000" y1="1104" y2="1104" x1="1360" />
        </branch>
        <instance x="1440" y="752" name="XLXI_1" orien="R0" />
        <instance x="1440" y="912" name="XLXI_2" orien="R0" />
        <branch name="XLXN_6">
            <wire x2="1840" y1="720" y2="720" x1="1664" />
            <wire x2="2000" y1="720" y2="720" x1="1840" />
            <wire x2="1840" y1="720" y2="880" x1="1840" />
            <wire x2="2000" y1="880" y2="880" x1="1840" />
        </branch>
        <branch name="XLXN_7">
            <wire x2="1760" y1="880" y2="880" x1="1664" />
            <wire x2="1760" y1="880" y2="1040" x1="1760" />
            <wire x2="2000" y1="1040" y2="1040" x1="1760" />
            <wire x2="1760" y1="784" y2="800" x1="1760" />
            <wire x2="1760" y1="800" y2="880" x1="1760" />
            <wire x2="2000" y1="784" y2="784" x1="1760" />
        </branch>
        <instance x="2000" y="848" name="XLXI_3" orien="R0" />
        <instance x="2000" y="1008" name="XLXI_4" orien="R0" />
        <instance x="2000" y="1168" name="XLXI_5" orien="R0" />
        <instance x="2000" y="1328" name="XLXI_6" orien="R0" />
        <branch name="XLXN_10">
            <wire x2="2480" y1="752" y2="752" x1="2256" />
        </branch>
        <branch name="XLXN_11">
            <wire x2="2480" y1="912" y2="912" x1="2256" />
        </branch>
        <branch name="XLXN_12">
            <wire x2="2480" y1="1072" y2="1072" x1="2256" />
        </branch>
        <branch name="XLXN_13">
            <wire x2="2480" y1="1232" y2="1232" x1="2256" />
        </branch>
        <instance x="2480" y="880" name="XLXI_7" orien="R0" />
        <instance x="2480" y="1040" name="XLXI_8" orien="R0" />
        <instance x="2480" y="1200" name="XLXI_9" orien="R0" />
        <instance x="2480" y="1360" name="XLXI_10" orien="R0" />
        <instance x="2880" y="1184" name="XLXI_11" orien="R0" />
        <branch name="XLXN_14">
            <wire x2="2880" y1="784" y2="784" x1="2736" />
            <wire x2="2880" y1="784" y2="928" x1="2880" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="2800" y1="944" y2="944" x1="2736" />
            <wire x2="2800" y1="944" y2="992" x1="2800" />
            <wire x2="2880" y1="992" y2="992" x1="2800" />
        </branch>
        <branch name="XLXN_16">
            <wire x2="2800" y1="1104" y2="1104" x1="2736" />
            <wire x2="2800" y1="1056" y2="1104" x1="2800" />
            <wire x2="2880" y1="1056" y2="1056" x1="2800" />
        </branch>
        <branch name="XLXN_17">
            <wire x2="2880" y1="1264" y2="1264" x1="2736" />
            <wire x2="2880" y1="1120" y2="1264" x1="2880" />
        </branch>
        <branch name="I0">
            <wire x2="2320" y1="1360" y2="1360" x1="1680" />
            <wire x2="2480" y1="816" y2="816" x1="2320" />
            <wire x2="2320" y1="816" y2="1360" x1="2320" />
        </branch>
        <branch name="I1">
            <wire x2="2352" y1="1440" y2="1440" x1="1680" />
            <wire x2="2480" y1="976" y2="976" x1="2352" />
            <wire x2="2352" y1="976" y2="1392" x1="2352" />
            <wire x2="2352" y1="1392" y2="1440" x1="2352" />
        </branch>
        <branch name="I3">
            <wire x2="2416" y1="1600" y2="1600" x1="1680" />
            <wire x2="2448" y1="1296" y2="1296" x1="2416" />
            <wire x2="2480" y1="1296" y2="1296" x1="2448" />
            <wire x2="2416" y1="1296" y2="1600" x1="2416" />
        </branch>
        <branch name="I2">
            <wire x2="2032" y1="1520" y2="1520" x1="1680" />
            <wire x2="2384" y1="1520" y2="1520" x1="2032" />
            <wire x2="2400" y1="1136" y2="1136" x1="2384" />
            <wire x2="2416" y1="1136" y2="1136" x1="2400" />
            <wire x2="2480" y1="1136" y2="1136" x1="2416" />
            <wire x2="2384" y1="1136" y2="1520" x1="2384" />
        </branch>
        <iomarker fontsize="28" x="1680" y="1360" name="I0" orien="R180" />
        <iomarker fontsize="28" x="1680" y="1440" name="I1" orien="R180" />
        <iomarker fontsize="28" x="1680" y="1520" name="I2" orien="R180" />
        <iomarker fontsize="28" x="1680" y="1600" name="I3" orien="R180" />
        <branch name="o">
            <wire x2="3200" y1="1024" y2="1024" x1="3136" />
        </branch>
        <iomarker fontsize="28" x="3200" y="1024" name="o" orien="R0" />
    </sheet>
</drawing>