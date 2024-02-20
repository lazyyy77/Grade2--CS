<?xml version="1.0" encoding="UTF-8"?>
<drawing version="7">
    <attr value="kintex7" name="DeviceFamilyName">
        <trait delete="all:0" />
        <trait editname="all:0" />
        <trait edittrait="all:0" />
    </attr>
    <netlist>
        <signal name="XLXN_4" />
        <signal name="XLXN_5" />
        <signal name="XLXN_6" />
        <signal name="Co" />
        <signal name="Ci" />
        <signal name="A(3:0)" />
        <signal name="B(3:0)" />
        <signal name="A(3)" />
        <signal name="A(1)" />
        <signal name="A(0)" />
        <signal name="A(2)" />
        <signal name="B(3)" />
        <signal name="B(2)" />
        <signal name="B(1)" />
        <signal name="B(0)" />
        <signal name="XLXN_26" />
        <signal name="XLXN_27" />
        <signal name="XLXN_28" />
        <signal name="XLXN_29" />
        <signal name="XLXN_31" />
        <signal name="XLXN_32" />
        <signal name="XLXN_33" />
        <signal name="S(3:0)" />
        <signal name="S(3)" />
        <signal name="S(2)" />
        <signal name="S(1)" />
        <signal name="S(0)" />
        <signal name="XLXN_43" />
        <signal name="XLXN_44" />
        <signal name="XLXN_45" />
        <signal name="XLXN_46" />
        <port polarity="Output" name="Co" />
        <port polarity="Input" name="Ci" />
        <port polarity="Input" name="A(3:0)" />
        <port polarity="Input" name="B(3:0)" />
        <port polarity="Output" name="S(3:0)" />
        <blockdef name="Adder1b">
            <timestamp>2023-11-9T23:35:7</timestamp>
            <rect width="256" x="64" y="-192" height="192" />
            <line x2="0" y1="-160" y2="-160" x1="64" />
            <line x2="0" y1="-96" y2="-96" x1="64" />
            <line x2="0" y1="-32" y2="-32" x1="64" />
            <line x2="384" y1="-160" y2="-160" x1="320" />
            <line x2="384" y1="-32" y2="-32" x1="320" />
        </blockdef>
        <block symbolname="Adder1b" name="XLXI_1">
            <blockpin signalname="B(0)" name="B" />
            <blockpin signalname="Ci" name="C" />
            <blockpin signalname="A(0)" name="A" />
            <blockpin signalname="XLXN_4" name="Co" />
            <blockpin signalname="S(0)" name="S" />
        </block>
        <block symbolname="Adder1b" name="XLXI_2">
            <blockpin signalname="B(1)" name="B" />
            <blockpin signalname="XLXN_4" name="C" />
            <blockpin signalname="A(1)" name="A" />
            <blockpin signalname="XLXN_5" name="Co" />
            <blockpin signalname="S(1)" name="S" />
        </block>
        <block symbolname="Adder1b" name="XLXI_3">
            <blockpin signalname="B(2)" name="B" />
            <blockpin signalname="XLXN_5" name="C" />
            <blockpin signalname="A(2)" name="A" />
            <blockpin signalname="XLXN_6" name="Co" />
            <blockpin signalname="S(2)" name="S" />
        </block>
        <block symbolname="Adder1b" name="XLXI_4">
            <blockpin signalname="B(3)" name="B" />
            <blockpin signalname="XLXN_6" name="C" />
            <blockpin signalname="A(3)" name="A" />
            <blockpin signalname="Co" name="Co" />
            <blockpin signalname="S(3)" name="S" />
        </block>
    </netlist>
    <sheet sheetnum="1" width="3520" height="2720">
        <instance x="1536" y="1472" name="XLXI_2" orien="R0">
        </instance>
        <instance x="1536" y="1792" name="XLXI_3" orien="R0">
        </instance>
        <instance x="1536" y="2112" name="XLXI_4" orien="R0">
        </instance>
        <branch name="XLXN_4">
            <wire x2="1440" y1="1200" y2="1376" x1="1440" />
            <wire x2="1520" y1="1376" y2="1376" x1="1440" />
            <wire x2="1536" y1="1376" y2="1376" x1="1520" />
            <wire x2="2000" y1="1200" y2="1200" x1="1440" />
            <wire x2="2000" y1="992" y2="992" x1="1920" />
            <wire x2="2000" y1="992" y2="1200" x1="2000" />
        </branch>
        <branch name="XLXN_5">
            <wire x2="2000" y1="1520" y2="1520" x1="1440" />
            <wire x2="1440" y1="1520" y2="1696" x1="1440" />
            <wire x2="1536" y1="1696" y2="1696" x1="1440" />
            <wire x2="1936" y1="1312" y2="1312" x1="1920" />
            <wire x2="1984" y1="1312" y2="1312" x1="1936" />
            <wire x2="2000" y1="1312" y2="1312" x1="1984" />
            <wire x2="2000" y1="1312" y2="1520" x1="2000" />
        </branch>
        <branch name="XLXN_6">
            <wire x2="2000" y1="1840" y2="1840" x1="1440" />
            <wire x2="1440" y1="1840" y2="2016" x1="1440" />
            <wire x2="1536" y1="2016" y2="2016" x1="1440" />
            <wire x2="2000" y1="1632" y2="1632" x1="1920" />
            <wire x2="2000" y1="1632" y2="1840" x1="2000" />
        </branch>
        <branch name="Co">
            <wire x2="2560" y1="1952" y2="1952" x1="1920" />
        </branch>
        <branch name="Ci">
            <wire x2="736" y1="640" y2="640" x1="720" />
            <wire x2="1440" y1="640" y2="640" x1="736" />
            <wire x2="1440" y1="640" y2="1056" x1="1440" />
            <wire x2="1536" y1="1056" y2="1056" x1="1440" />
        </branch>
        <branch name="A(3:0)">
            <wire x2="720" y1="800" y2="800" x1="640" />
            <wire x2="720" y1="800" y2="880" x1="720" />
            <wire x2="720" y1="880" y2="1040" x1="720" />
            <wire x2="720" y1="1040" y2="1168" x1="720" />
            <wire x2="720" y1="1168" y2="1200" x1="720" />
            <wire x2="720" y1="1200" y2="1280" x1="720" />
            <wire x2="720" y1="1280" y2="1360" x1="720" />
            <wire x2="720" y1="1360" y2="1440" x1="720" />
        </branch>
        <branch name="B(3:0)">
            <wire x2="720" y1="1520" y2="1520" x1="640" />
            <wire x2="720" y1="1520" y2="1600" x1="720" />
            <wire x2="720" y1="1600" y2="1760" x1="720" />
            <wire x2="720" y1="1760" y2="1920" x1="720" />
            <wire x2="720" y1="1920" y2="2080" x1="720" />
            <wire x2="720" y1="2080" y2="2160" x1="720" />
        </branch>
        <iomarker fontsize="28" x="640" y="800" name="A(3:0)" orien="R180" />
        <iomarker fontsize="28" x="640" y="1520" name="B(3:0)" orien="R180" />
        <bustap x2="816" y1="1360" y2="1360" x1="720" />
        <bustap x2="816" y1="1040" y2="1040" x1="720" />
        <branch name="A(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="1040" type="branch" />
            <wire x2="832" y1="1040" y2="1040" x1="816" />
            <wire x2="848" y1="1040" y2="1040" x1="832" />
            <wire x2="1072" y1="1040" y2="1040" x1="848" />
            <wire x2="1072" y1="1040" y2="1440" x1="1072" />
            <wire x2="1088" y1="1440" y2="1440" x1="1072" />
            <wire x2="1536" y1="1440" y2="1440" x1="1088" />
        </branch>
        <bustap x2="816" y1="880" y2="880" x1="720" />
        <bustap x2="816" y1="1200" y2="1200" x1="720" />
        <branch name="A(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="1200" type="branch" />
            <wire x2="832" y1="1200" y2="1200" x1="816" />
            <wire x2="848" y1="1200" y2="1200" x1="832" />
            <wire x2="1104" y1="1200" y2="1200" x1="848" />
            <wire x2="1104" y1="1200" y2="1360" x1="1104" />
            <wire x2="1104" y1="1360" y2="1760" x1="1104" />
            <wire x2="1120" y1="1760" y2="1760" x1="1104" />
            <wire x2="1536" y1="1760" y2="1760" x1="1120" />
        </branch>
        <bustap x2="816" y1="2080" y2="2080" x1="720" />
        <branch name="B(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="2080" type="branch" />
            <wire x2="832" y1="2080" y2="2080" x1="816" />
            <wire x2="848" y1="2080" y2="2080" x1="832" />
            <wire x2="848" y1="2080" y2="2112" x1="848" />
            <wire x2="1264" y1="2112" y2="2112" x1="848" />
            <wire x2="1536" y1="1952" y2="1952" x1="1264" />
            <wire x2="1264" y1="1952" y2="2112" x1="1264" />
        </branch>
        <bustap x2="816" y1="1920" y2="1920" x1="720" />
        <branch name="B(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="1920" type="branch" />
            <wire x2="832" y1="1920" y2="1920" x1="816" />
            <wire x2="848" y1="1920" y2="1920" x1="832" />
            <wire x2="1232" y1="1920" y2="1920" x1="848" />
            <wire x2="1232" y1="1632" y2="1920" x1="1232" />
            <wire x2="1536" y1="1632" y2="1632" x1="1232" />
        </branch>
        <bustap x2="816" y1="1760" y2="1760" x1="720" />
        <branch name="B(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="1760" type="branch" />
            <wire x2="832" y1="1760" y2="1760" x1="816" />
            <wire x2="848" y1="1760" y2="1760" x1="832" />
            <wire x2="848" y1="1760" y2="1792" x1="848" />
            <wire x2="1200" y1="1792" y2="1792" x1="848" />
            <wire x2="1536" y1="1312" y2="1312" x1="1200" />
            <wire x2="1200" y1="1312" y2="1792" x1="1200" />
        </branch>
        <bustap x2="816" y1="1600" y2="1600" x1="720" />
        <branch name="B(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="1600" type="branch" />
            <wire x2="832" y1="1600" y2="1600" x1="816" />
            <wire x2="848" y1="1600" y2="1600" x1="832" />
            <wire x2="1168" y1="1600" y2="1600" x1="848" />
            <wire x2="1168" y1="992" y2="1600" x1="1168" />
            <wire x2="1536" y1="992" y2="992" x1="1168" />
        </branch>
        <branch name="A(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="880" type="branch" />
            <wire x2="832" y1="880" y2="880" x1="816" />
            <wire x2="848" y1="880" y2="880" x1="832" />
            <wire x2="1040" y1="880" y2="880" x1="848" />
            <wire x2="1040" y1="880" y2="1120" x1="1040" />
            <wire x2="1536" y1="1120" y2="1120" x1="1040" />
        </branch>
        <branch name="A(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="832" y="1360" type="branch" />
            <wire x2="832" y1="1360" y2="1360" x1="816" />
            <wire x2="848" y1="1360" y2="1360" x1="832" />
            <wire x2="1040" y1="1360" y2="1360" x1="848" />
            <wire x2="1088" y1="1360" y2="1360" x1="1040" />
            <wire x2="1088" y1="1344" y2="1360" x1="1088" />
            <wire x2="1120" y1="1344" y2="1344" x1="1088" />
            <wire x2="1120" y1="1344" y2="1360" x1="1120" />
            <wire x2="1136" y1="1360" y2="1360" x1="1120" />
            <wire x2="1136" y1="1360" y2="2080" x1="1136" />
            <wire x2="1536" y1="2080" y2="2080" x1="1136" />
        </branch>
        <branch name="S(3:0)">
            <wire x2="2560" y1="960" y2="1040" x1="2560" />
            <wire x2="2560" y1="1040" y2="1200" x1="2560" />
            <wire x2="2560" y1="1200" y2="1280" x1="2560" />
            <wire x2="2560" y1="1280" y2="1360" x1="2560" />
            <wire x2="2560" y1="1360" y2="1440" x1="2560" />
            <wire x2="2560" y1="1440" y2="1520" x1="2560" />
            <wire x2="2560" y1="1520" y2="1680" x1="2560" />
        </branch>
        <iomarker fontsize="28" x="720" y="640" name="Ci" orien="R180" />
        <iomarker fontsize="28" x="2560" y="960" name="S(3:0)" orien="R270" />
        <bustap x2="2464" y1="1520" y2="1520" x1="2560" />
        <branch name="S(3)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2440" y="1520" type="branch" />
            <wire x2="2224" y1="2080" y2="2080" x1="1920" />
            <wire x2="2224" y1="1520" y2="2080" x1="2224" />
            <wire x2="2416" y1="1520" y2="1520" x1="2224" />
            <wire x2="2440" y1="1520" y2="1520" x1="2416" />
            <wire x2="2464" y1="1520" y2="1520" x1="2440" />
        </branch>
        <bustap x2="2464" y1="1360" y2="1360" x1="2560" />
        <branch name="S(2)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2440" y="1360" type="branch" />
            <wire x2="2256" y1="1760" y2="1760" x1="1920" />
            <wire x2="2256" y1="1360" y2="1760" x1="2256" />
            <wire x2="2416" y1="1360" y2="1360" x1="2256" />
            <wire x2="2440" y1="1360" y2="1360" x1="2416" />
            <wire x2="2464" y1="1360" y2="1360" x1="2440" />
        </branch>
        <bustap x2="2464" y1="1200" y2="1200" x1="2560" />
        <branch name="S(1)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2440" y="1200" type="branch" />
            <wire x2="2288" y1="1440" y2="1440" x1="1920" />
            <wire x2="2288" y1="1200" y2="1440" x1="2288" />
            <wire x2="2416" y1="1200" y2="1200" x1="2288" />
            <wire x2="2440" y1="1200" y2="1200" x1="2416" />
            <wire x2="2464" y1="1200" y2="1200" x1="2440" />
        </branch>
        <bustap x2="2464" y1="1040" y2="1040" x1="2560" />
        <branch name="S(0)">
            <attrtext style="alignment:SOFT-BCENTER;fontsize:28;fontname:Arial" attrname="Name" x="2448" y="1040" type="branch" />
            <wire x2="2320" y1="1120" y2="1120" x1="1920" />
            <wire x2="2320" y1="1040" y2="1120" x1="2320" />
            <wire x2="2432" y1="1040" y2="1040" x1="2320" />
            <wire x2="2448" y1="1040" y2="1040" x1="2432" />
            <wire x2="2464" y1="1040" y2="1040" x1="2448" />
        </branch>
        <instance x="1536" y="1152" name="XLXI_1" orien="R0">
        </instance>
        <iomarker fontsize="28" x="2560" y="1952" name="Co" orien="R0" />
    </sheet>
</drawing>