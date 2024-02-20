<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="S(1:0)" />
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6(3:0)" />
        <signal name="XLXN_8(3:0)" />
        <signal name="B(3:0)" />
        <signal name="A(3:0)" />
        <signal name="XLXN_13(3:0)" />
        <signal name="XLXN_14" />
        <signal name="XLXN_15" />
        <signal name="XLXN_16" />
        <signal name="S(0)" />
        <signal name="C(3:0)" />
        <signal name="o" />
        <port polarity="Input" name="S(1:0)" />
        <port polarity="Input" name="B(3:0)" />
        <port polarity="Input" name="A(3:0)" />
        <port polarity="Output" name="C(3:0)" />
        <port polarity="Output" name="o" />
        <blockdef name="AddSub4b">
            <timestamp>2023-11-10T0:2:0</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <rect width="64" x="320" y="-44" height="24" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <blockdef name="Mux4to1b4_SCH">
            <timestamp>2023-11-9T16:10:8</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <rect width="64" x="0" y="-236" height="24" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <rect width="64" x="0" y="-172" height="24" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-300" height="24" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="Mux4to1">
            <timestamp>2023-11-9T17:3:18</timestamp>
            <rect width="256" x="64" y="-320" height="320" />
            <rect width="64" x="0" y="-300" height="24" />
            <line x2="0" y1="-288" y2="-288" x1="64" />
            <line x2="0" y1="-224" y2="-224" x1="64" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-288" y2="-288" x1="320" />
        </blockdef>
        <blockdef name="And2b4">
            <timestamp>2023-11-10T1:16:25</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="Or2b4">
            <timestamp>2023-11-10T1:18:5</timestamp>
            <rect width="256" x="64" y="-128" height="128" />
            <rect width="64" x="0" y="-108" height="24" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <rect width="64" x="0" y="-44" height="24" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <rect width="64" x="320" y="-108" height="24" />
            <line x2="384" y1="-96" y2="-96" x1="320" />
        </blockdef>
        <blockdef name="gnd">
            <timestamp>2000-1-1T10:10:10</timestamp>
            <line x2="64" y1="-64" y2="-96" x1="64" />
            <line x2="52" y1="-48" y2="-48" x1="76" />
            <line x2="60" y1="-32" y2="-32" x1="68" />
            <line x2="40" y1="-64" y2="-64" x1="88" />
            <line x2="64" y1="-64" y2="-80" x1="64" />
            <line x2="64" y1="-128" y2="-96" x1="64" />
        </blockdef>
        <block symbolname="Mux4to1b4_SCH" name="XLXI_2">
            <blockpin signalname="S(1:0)" name="s(1:0)" />
            <blockpin signalname="XLXN_6(3:0)" name="I0(3:0)" />
            <blockpin signalname="XLXN_6(3:0)" name="I1(3:0)" />
            <blockpin signalname="XLXN_13(3:0)" name="I2(3:0)" />
            <blockpin signalname="XLXN_8(3:0)" name="I3(3:0)" />
            <blockpin signalname="C(3:0)" name="o(3:0)" />
        </block>
        <block symbolname="Mux4to1" name="XLXI_3">
            <blockpin signalname="S(1:0)" name="s(1:0)" />
            <blockpin signalname="XLXN_4" name="I0" />
            <blockpin signalname="XLXN_4" name="I1" />
            <blockpin signalname="XLXN_15" name="I3" />
            <blockpin signalname="XLXN_15" name="I2" />
            <blockpin signalname="o" name="o" />
        </block>
        <block symbolname="AddSub4b" name="XLXI_1">
            <blockpin signalname="A(3:0)" name="A(3:0)" />
            <blockpin signalname="B(3:0)" name="B(3:0)" />
            <blockpin signalname="S(0)" name="Ctrl" />
            <blockpin signalname="XLXN_4" name="Co" />
            <blockpin signalname="XLXN_6(3:0)" name="S(3:0)" />
        </block>
        <block symbolname="Or2b4" name="XLXI_5">
            <blockpin signalname="A(3:0)" name="A(3:0)" />
            <blockpin signalname="B(3:0)" name="B(3:0)" />
            <blockpin signalname="XLXN_8(3:0)" name="C(3:0)" />
        </block>
        <block symbolname="And2b4" name="XLXI_4">
            <blockpin signalname="A(3:0)" name="A(3:0)" />
            <blockpin signalname="B(3:0)" name="B(3:0)" />
            <blockpin signalname="XLXN_13(3:0)" name="C(3:0)" />
        </block>
        <block symbolname="gnd" name="XLXI_11">
            <blockpin signalname="XLXN_15" name="G" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="2176" y="1200" name="XLXI_2" orien="R0">
        </instance>
        <instance x="2176" y="1680" name="XLXI_3" orien="R0">
        </instance>
        <branch name="S(1:0)">
            <wire x2="1360" y1="720" y2="720" x1="960" />
            <wire x2="2080" y1="720" y2="720" x1="1360" />
            <wire x2="2080" y1="720" y2="912" x1="2080" />
            <wire x2="2080" y1="912" y2="1392" x1="2080" />
            <wire x2="2176" y1="1392" y2="1392" x1="2080" />
            <wire x2="2176" y1="912" y2="912" x1="2080" />
        </branch>
        <branch name="XLXN_4">
            <wire x2="2000" y1="912" y2="912" x1="1840" />
            <wire x2="2000" y1="912" y2="1456" x1="2000" />
            <wire x2="2176" y1="1456" y2="1456" x1="2000" />
            <wire x2="2000" y1="1456" y2="1520" x1="2000" />
            <wire x2="2176" y1="1520" y2="1520" x1="2000" />
        </branch>
        <branch name="XLXN_6(3:0)">
            <wire x2="1920" y1="1040" y2="1040" x1="1840" />
            <wire x2="2176" y1="1040" y2="1040" x1="1920" />
            <wire x2="1920" y1="976" y2="1040" x1="1920" />
            <wire x2="2176" y1="976" y2="976" x1="1920" />
        </branch>
        <branch name="XLXN_8(3:0)">
            <wire x2="1840" y1="1472" y2="1472" x1="1760" />
            <wire x2="2176" y1="1168" y2="1168" x1="1840" />
            <wire x2="1840" y1="1168" y2="1472" x1="1840" />
        </branch>
        <instance x="1456" y="1072" name="XLXI_1" orien="R0">
        </instance>
        <instance x="1376" y="1568" name="XLXI_5" orien="R0">
        </instance>
        <instance x="1376" y="1328" name="XLXI_4" orien="R0">
        </instance>
        <branch name="B(3:0)">
            <wire x2="1120" y1="976" y2="976" x1="960" />
            <wire x2="1376" y1="976" y2="976" x1="1120" />
            <wire x2="1456" y1="976" y2="976" x1="1376" />
            <wire x2="1120" y1="976" y2="1296" x1="1120" />
            <wire x2="1120" y1="1296" y2="1536" x1="1120" />
            <wire x2="1376" y1="1536" y2="1536" x1="1120" />
            <wire x2="1376" y1="1296" y2="1296" x1="1120" />
        </branch>
        <branch name="A(3:0)">
            <wire x2="1200" y1="912" y2="912" x1="960" />
            <wire x2="1376" y1="912" y2="912" x1="1200" />
            <wire x2="1456" y1="912" y2="912" x1="1376" />
            <wire x2="1200" y1="912" y2="1232" x1="1200" />
            <wire x2="1200" y1="1232" y2="1472" x1="1200" />
            <wire x2="1376" y1="1472" y2="1472" x1="1200" />
            <wire x2="1376" y1="1232" y2="1232" x1="1200" />
        </branch>
        <iomarker fontsize="28" x="960" y="976" name="B(3:0)" orien="R180" />
        <iomarker fontsize="28" x="960" y="912" name="A(3:0)" orien="R180" />
        <branch name="XLXN_13(3:0)">
            <wire x2="1920" y1="1232" y2="1232" x1="1760" />
            <wire x2="2176" y1="1104" y2="1104" x1="1920" />
            <wire x2="1920" y1="1104" y2="1232" x1="1920" />
        </branch>
        <branch name="XLXN_15">
            <wire x2="2080" y1="1584" y2="1584" x1="2000" />
            <wire x2="2160" y1="1584" y2="1584" x1="2080" />
            <wire x2="2176" y1="1584" y2="1584" x1="2160" />
            <wire x2="2080" y1="1584" y2="1648" x1="2080" />
            <wire x2="2160" y1="1648" y2="1648" x1="2080" />
            <wire x2="2176" y1="1648" y2="1648" x1="2160" />
            <wire x2="2000" y1="1584" y2="1600" x1="2000" />
        </branch>
        <instance x="1936" y="1728" name="XLXI_11" orien="R0" />
        <iomarker fontsize="28" x="960" y="720" name="S(1:0)" orien="R180" />
        <bustap x2="1360" y1="720" y2="816" x1="1360" />
        <branch name="S(0)">
            <attrtext style="alignment:SOFT-TVCENTER;fontsize:28;fontname:Arial" attrname="Name" x="1360" y="824" type="branch" />
            <wire x2="1360" y1="816" y2="824" x1="1360" />
            <wire x2="1360" y1="824" y2="832" x1="1360" />
            <wire x2="1360" y1="832" y2="1040" x1="1360" />
            <wire x2="1456" y1="1040" y2="1040" x1="1360" />
        </branch>
        <branch name="C(3:0)">
            <wire x2="2640" y1="912" y2="912" x1="2560" />
        </branch>
        <branch name="o">
            <wire x2="2640" y1="1392" y2="1392" x1="2560" />
        </branch>
        <iomarker fontsize="28" x="2640" y="912" name="C(3:0)" orien="R0" />
        <iomarker fontsize="28" x="2640" y="1392" name="o" orien="R0" />
    </sheet>
</drawing>